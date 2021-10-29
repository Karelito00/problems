#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 51, MOD = 1e9 + 7;

long long sol[MAXn][MAXn];
long long mat[MAXn][MAXn];
int cam[MAXn][MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin>>n1>>n2;
        cam[n1][n2]++;
        sol[n1][n2]++;
    }
    int q;
    cin>>q;
    q--;
    while(q--){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = sol[i][j];
                sol[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mat[i][j])
                for(int k = 1; k <= n; k++){
                    if(cam[j][k])
                        sol[i][k] = (sol[i][k] + (mat[i][j] * cam[j][k])) % MOD;
                }
            }
        }
    }
    cout<<sol[1][n];
    return 0;
}
