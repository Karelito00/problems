#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 251, MOD = 1e9 + 7;

long long dp[MAXn][MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i <= 250; i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i <= 250; i++){
        for(int j = 1; j <= 250; j++){
            for(int k = 0; k + i <= 250; k++){
                dp[i + k][j + 1] = (dp[i + k][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        cout<<dp[n][k]<<"\n";
    }
    return 0;
}
