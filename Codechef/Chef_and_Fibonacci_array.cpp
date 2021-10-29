#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

const long long MAXn = 134;
long long MOD = (1e9) + 7;

long long A[MAXn];
long long dp[MAXn + 5][MAXn + 5][MAXn + 5];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin >> A[i];

        dp[2][A[1]][A[2]] = 1;
        for(long long i = 2;i < MAXn;i++){
            for(long long j = 0;j < MAXn;j++){
                for(long long k = 0;k < MAXn;k++){
                    if(dp[i][j][k]){
                        for(long long c = 0;c <= mn(j,k);c++)
                            dp[i + 1][k - c][A[i + 1] + c] = (dp[i + 1][k - c][A[i + 1] + c] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }
        long long sol = 0;
        for(long long j = 0;j < MAXn;j++)
            for(long long k = 0;k < MAXn;k++)
                sol = (sol + dp[MAXn][j][k]) % MOD;

        cout << sol << '\n';
        for(long long i = 2; i <= MAXn; i++){
            for(long long j = 0; j < MAXn; j++){
                for(long long k = 0; k < MAXn; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        for(long long i = 1; i <= n; i++)
            A[i] = 0;
    }
    return 0;
}
