#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct trio{
    char val;
    int y1;
    int x1;
    bool operator < (const trio &var) const {
        return var.val > val;
    }
};

typedef pair < int , int > par;

int const MAXn = 4e3 + 1;

char sol[MAXn];
char mat[MAXn][MAXn];
bool visited[MAXn][MAXn];
int n, m;

void dfs(int y, int x, int pos){
    sol[pos] = mat[y][x];
    if(y == n - 1 && x == m - 1)
        return;
    if(y + 1 == n)
        dfs(y, x + 1, pos + 1);
    else if(x + 1 == m)
        dfs(y + 1, x, pos + 1);
    else{
        if(mat[y + 1][x] < mat[y][x + 1]) dfs(y + 1, x, pos + 1);
        else if(mat[y + 1][x] > mat[y][x + 1]) dfs(y, x + 1, pos + 1);
        else{
            queue < par > cola;
            cola.push(mp(y + 1, x));
            cola.push(mp(y, x + 1));
            sol[++pos] = mat[y][x + 1];
            while(cola.size() != 1){
                vector < trio > num;
                while(!cola.empty()){
                    par v = cola.front();
                    cola.pop();
                    if(v.f + 1 < n && !visited[v.f + 1][v.s]){
                        visited[v.f + 1][v.s] = true;
                        num.push_back(trio{mat[v.f + 1][v.s], v.f + 1, v.s});
                    }
                    if(v.s + 1 < m && !visited[v.f][v.s + 1]){
                        visited[v.f][v.s + 1] = true;
                        num.push_back(trio{mat[v.f][v.s + 1], v.f, v.s + 1});
                    }
                }
                sort(all(num));
                cola.push(mp(num[0].y1, num[0].x1));
                for(int i = 1; i < (int)num.size(); i++){
                    if(num[i].val != num[i - 1].val) break;
                    cola.push(mp(num[i].y1, num[i].x1));
                }
                sol[++pos] = num[0].val;
            }
            dfs(cola.front().f, cola.front().s, pos);
        }
    }
}

int main()
{
    freopen("pohlepko.in","r",stdin);
    freopen("pohlepko.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin>>mat[i][j];
    }
    fill(sol, sol + n + m - 1, 'z');
    dfs(0, 0, 0);
    cout<<sol;
    return 0;
}
