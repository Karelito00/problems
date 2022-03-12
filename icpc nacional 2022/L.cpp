#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
typedef long long ll;

using namespace std;

int const MAXn = 2e3 + 2;

int mat[MAXn][MAXn];

vector < int > adya[2 * MAXn];
set < int > diff[2 * MAXn];
int comp[2 * MAXn];
int cnt;
int col[2 * MAXn];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>mat[i][j];
            if(mat[i][j] != mat[i - 1][j] && mat[i][j] != mat[i][j - 1] && mat[i][j] == mat[i - 1][j - 1] + 1) {
                adya[i].push_back(n + j);
                adya[n + j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= n + m; i++) {
        if(!comp[i]) { 
            queue < int > cola;
            cola.push(i);
            cnt++;
            comp[i] = cnt;
            while(!cola.empty()) {
                int v = cola.front();
                cola.pop();
                for(auto u: adya[v]) {
                    if(comp[u]) continue;
                    comp[u] = cnt;
                    cola.push(u);
                }
            }
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mat[i][j] == mat[i - 1][j] && mat[i][j] == mat[i][j - 1] && mat[i][j] == mat[i - 1][j - 1]) {
                diff[comp[i]].insert(comp[n + j]);
                diff[comp[n + j]].insert(comp[i]);
            }
        }
    }

    for(int i = 1; i <= n + m; i++) {
        if(col[comp[i]]) continue;
        col[comp[i]] = 1;
        queue < int > cola;
        cola.push(comp[i]);
        cnt++;
        while(!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for(auto u: diff[v]) {
                if(col[u]) continue;
                col[u] = col[v] == 1 ? 2 : 1;
                cola.push(u);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout<<col[comp[i]] - 1;
    }
    cout<<"\n";
    for(int i = 1; i <= m; i++) {
        cout<<col[comp[i + n]] - 1;
    }
    cout<<"\n";

    return 0;
}
