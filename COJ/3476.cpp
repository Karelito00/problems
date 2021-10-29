#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7;
int dp[1001][1001][2];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    long long perh = 1, perm = 1;
    int con = 1;
    while(con <= m){
        perm = (perm * con) % MOD;
        con++;
    }
    perh = perm;
    while(con <= n){
        perh = (perh * con) % MOD;
        con++;
    }
    dp[0][1][1] = 1;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
        }
        dp[i][m][0] = (dp[i][m][0] + dp[i - 1][m][0] + dp[i - 1][m][1]) % MOD;
    }
    long long aux = (dp[n][m][0] + dp[n][m][1]) % MOD;
    long long sol = (aux * perm) % MOD;
    cout<<(sol * perh) % MOD;
    return 0;
}
