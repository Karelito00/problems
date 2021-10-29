#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

double dp[102][605];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 6; i++)
        dp[1][i] = (double)1/(double)6;
    for(int i = 1; i <= 99; i++){
        for(int j = 1; j <= i * 6; j++){
            for(int k = 1; k <= 6 && k + j <= 600; k++){
                dp[i + 1][j + k] += dp[i][j]/6;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        cout<<fixed<<setprecision(2)<<dp[n][m]<<"\n";
    }
    return 0;
}
