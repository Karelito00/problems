#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long dp[11][11];
int arr[11];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int y = 1; y <= t; y++){
        int n, k;
        cin>>n>>k;
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            dp[1][arr[i]]++;
        }
        long long sol = 0;
        for(int i = 1; i < k; i++){
            for(int j = 1; j <= 9; j++){
                for(int u = 1; u <= n; u++){
                    if(abs(arr[u] - j) <= 2)
                        dp[i + 1][arr[u]] += dp[i][j];
                }
            }
        }
        for(int i = 1; i <= n; i++)
            sol += dp[k][arr[i]];
        for(int i = 1; i <= k; i++)
            fill(dp[i] + 1, dp[i] + 10, 0);
        cout<<"Case "<<y<<": "<<sol<<"\n";
    }
    return 0;
}
