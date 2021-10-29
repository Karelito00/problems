#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 501;
int n, k;
int dp[MAXn][MAXn];

struct coor{
    int y, x;
}arr[MAXn];

int funt(int y1, int x1, int y2, int x2){
    return abs(y1 - y2) + abs(x1 - x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>arr[i].y>>arr[i].x;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    }
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int u = 0; u <= k - (j - i - 1); u++)
                if(dp[i][u] != INT_MAX)
                    dp[j][j - i - 1 + u] = mn(funt(arr[i].y, arr[i].x, arr[j].y, arr[j].x) + dp[i][u], dp[j][j - i - 1 + u]);
        }
    }
    cout<<dp[n][k];
    return 0;
}
