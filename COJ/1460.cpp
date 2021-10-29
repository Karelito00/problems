#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e4 + 2, MAXk = 1e3 + 2;

int dp[2][MAXk][2];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int j = 0; j <= k; j++)
        dp[0][j][1] = dp[0][j][0] = -INT_MAX;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        for(int j = 0; j <= k; j++)
            dp[i % 2][j][1] = dp[i % 2][j][0] = -INT_MAX;
        for(int j = 0; j <= k; j++){
            if(dp[((i - 1) + 2) % 2][j][0] != -INT_MAX){
                dp[i % 2][j][0] = mx(dp[i % 2][j][0], dp[((i - 1) + 2) % 2][j][0]);
                dp[i % 2][j + 1][1] = mx(dp[i % 2][j + 1][1], dp[((i - 1) + 2) % 2][j][0] + x);
            }
            if(dp[((i - 1) + 2) % 2][j][1] != -INT_MAX){
                dp[i % 2][j + 1][1] = mx(dp[i % 2][j + 1][1], dp[((i - 1) + 2) % 2][j][1] + x);
                dp[i % 2][j][1] = mx(dp[i % 2][j][1], dp[((i - 1) + 2) % 2][j][1] + x);
                dp[i % 2][j][0] = mx(dp[i % 2][j][0], dp[((i - 1) + 2) % 2][j][1]);
            }
        }
        dp[i % 2][0][0] = mx(dp[i % 2][0][0], 0);
    }
    cout<<mx(dp[n % 2][k][0], dp[n % 2][k][1]);
    return 0;
}
