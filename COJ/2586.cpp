#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, MOD = 5000011;

long long dp[MAXn][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin>>n>>l;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i][0] + dp[i - 1][0] + dp[i - 1][1]) % MOD;
        if(i <= l + 1) dp[i][1]++;
        else{
            dp[i][1] = (dp[i][1] + dp[i - l][0]) % MOD;
        }
    }
    cout<<(dp[n][0] + dp[n][1]) % MOD;
    return 0;
}
