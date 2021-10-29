#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 2, MOD = 1e9 + 7;

long long dp[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[2] = 1;
    for(int i = 3; i <= MAXn - 2; i++)
        dp[i] = ((dp[i - 1] * (i - 2)) + 1) % MOD;
    int n;
    while(cin>>n){
        cout<<dp[n]<<"\n";
    }
    return 0;
}
