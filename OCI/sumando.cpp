#include <bits/stdc++.h>

using namespace std;

const long long m = 1e14;
long long dp[10050];

int main()
{
    freopen("sumando.in","r",stdin);
    freopen("sumando.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    long long mod;
    cin>>n>>a>>b>>mod;
    dp[0] = 1;
    for(int i=a;i<=b;i++){
        for(int j=i;j<=n;j++){
            dp[j] = (dp[j] + dp[j-i]);
            if(dp[j] >= m)
                dp[j] = dp[j] % mod;
        }
    }
    cout<<dp[n]%mod;
    return 0;
}
