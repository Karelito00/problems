#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2, MOD = 1e9 + 7;;

long long dp[MAXn][MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1][1] = 10;
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            dp[2][(i == j ? 1 : 0)] += 1;
    for(int i = 1; i <= 998; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 9; k++){
                for(int k2 = 0; k2 <= 9; k2++){
                    if(k == k2)
                        dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % MOD;
                    else
                        dp[i + 2][j] = (dp[i + 2][j] + dp[i][j]) % MOD;
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<dp[a][b]<<"\n";
    }
    return 0;
}
