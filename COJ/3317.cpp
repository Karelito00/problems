#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 1, MOD = 1e9 + 7;

long long dp[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    dp[1] = 1;
    dp[2] = 2;
    int calc = 3;
    while(t--){
        int n;
        cin>>n;
        for(; calc <= n; calc++)
            dp[calc] = (dp[calc - 1] + dp[calc - 2]) % MOD;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
