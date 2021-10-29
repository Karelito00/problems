#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, MOD = 1e9 + 7;

int num[12];
int cad[MAXn];
char x;
long long dp[MAXn][12];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        cin>>x;
        num[i] = x - '0';
    }
    for(int i = 1; i <= n; i++){
        cin>>x;
        cad[i] = x - '0';
    }
    for(int i = 1; i <= n; i++){
        if(cad[i] == num[1]) dp[i][1] = (dp[i - 1][1] + 1) % MOD;
        else dp[i][1] = dp[i - 1][1];
        for(int j = 2; j <= m; j++){
            if(num[j] == cad[i])
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}
