#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 5e3 + 2;
char a[MAXn];
char b[MAXn];
int dp[MAXn][MAXn][2];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int j = 1; j <= m; j++)
            cin>>b[j];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j][0] = INT_MAX;
                dp[i][j][1] = INT_MAX;
            }
        }
        dp[1][0][0] = 1;
        dp[0][1][1] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == j && j == 0) continue;
                if(dp[i][j][0] != INT_MAX){
                    dp[i + 1][j][0] = mn(dp[i + 1][j][0], dp[i][j][0] + (a[i] != a[i + 1] ? 1 : 0));
                    dp[i][j + 1][1] = mn(dp[i][j + 1][1], dp[i][j][0] + (a[i] != b[j + 1] ? 1 : 0));
                }
                if(dp[i][j][1] != INT_MAX){
                    dp[i + 1][j][0] = mn(dp[i + 1][j][0], dp[i][j][1] + (b[j] != a[i + 1] ? 1 : 0));
                    dp[i][j + 1][1] = mn(dp[i][j + 1][1], dp[i][j][1] + (b[j] != b[j + 1] ? 1 : 0));
                }
            }
        }
        cout<<mn(dp[n][m][0], dp[n][m][1])<<"\n";
    }
    return 0;
}
