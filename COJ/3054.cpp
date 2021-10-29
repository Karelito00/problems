#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e6 + 3;
long long dp[MOD];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1] = 1;
    int con = 2;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n >= con){
            for(; con <= n; con++)
                dp[con] = (dp[con - 1] * con + 1) % MOD;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
