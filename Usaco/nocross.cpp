#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int id[1001];
int id2[1001];
int dp[1001][1001];

int main()
{
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>id[i];
    for(int i = 1; i <= n; i++)
        cin>>id2[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(abs(id[i] - id2[j]) <= 4)
                dp[i][j] = mx(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = mx(dp[i][j], mx(dp[i][j - 1], dp[i - 1][j]));
        }
    }
    cout<<dp[n][n];
    return 0;
}
