#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 10;

long long dp[MAXn][2];
long long arr[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    dp[1][0] = arr[1];
    for(int i = 2; i <= n + 2; i++){
        dp[i][1] = mx(dp[i - 1][1], dp[i - 2][0]);
        dp[i][0] = mx(dp[i - 1][1], dp[i - 2][0]) + arr[i];
    }
    cout<<mx(dp[n + 2][0],dp[n + 2][1]);
    return 0;
}
