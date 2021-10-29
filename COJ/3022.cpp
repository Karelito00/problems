#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int n, m;
double s, v;
pair < double , double > arr[102];
bool mat[102][102];
bool mark[102];
int match[102];

bool DFS(int v){
    for(int i = 1; i <= m; i++){
        if(!mark[i] && mat[v][i]){
            mark[i] = true;
            if(!match[i] || DFS(match[i])){
                match[i] = v;
                return 1;
            }
        }
    }
    return 0;
}

int hungary(){
    int sol = 0;
    for(int i = 1; i <= n; i++){
        if(DFS(i))
            sol++;
        fill(mark + 1, mark + m + 1, false);
    }
    return sol;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m>>s>>v){
        for(int i = 1; i <= n; i++)
            cin>>arr[i].f>>arr[i].s;
        for(int i = 1; i <= m; i++){
            double n1, n2;
            cin>>n1>>n2;
            for(int j = 1; j <= n; j++){
                double aux = (arr[j].f - n1) * (arr[j].f - n1);
                aux += (arr[j].s - n2) * (arr[j].s - n2);
                if(sqrt(aux) / v <= s)
                    mat[j][i] = true;
            }
        }
        cout<<n - hungary()<<"\n";
        fill(match + 1, match + m + 1, 0);
        for(int i = 1; i <= n; i++)
            fill(mat[i] + 1, mat[i] + m + 1, 0);
    }
    return 0;
}
