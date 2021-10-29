#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define MOD 1000000007

using namespace std;

int const MAXn = 2e3 + 10;

long long dp[MAXn][MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    dp[1][1] = 1;
    for(int i = 2; i < MAXn; i++){
        for(int j = 0; j <= MAXn / 2; j++){
            dp[i][j + 1] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
            if(j > 0)
                dp[i][j - 1] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    while(t--){
        int x;
        cin>>x;
        cout<<dp[x * 2][0]<<"\n";
    }
    return 0;
}
