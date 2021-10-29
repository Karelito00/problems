#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2, MOD = 1e9 + 7;

long long dp[102][MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 99; j >= 0; j--){
            for(int k = 0; k + i <= 1000; k++){
                dp[j + 1][k + i] = (dp[j + 1][k + i] + dp[j][k]) % MOD;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int v, k;
        cin>>v>>k;
        cout<<dp[k][v]<<"\n";
    }
    return 0;
}
