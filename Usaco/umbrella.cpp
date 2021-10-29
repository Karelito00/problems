#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 5001, MAXm = 1e5 + 1;

int arr[MAXn];
int M[MAXm];
long long dp[MAXn];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= m; i++)
        cin>>M[i];
    for(int i = m - 1; i >= 1; i--)
        M[i] = mn(M[i], M[i + 1]);
    fill(dp + 1, dp + n + 1, (long long)1e18);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            dp[j] = mn(dp[j], dp[i - 1] + M[arr[j] - arr[i] + 1]);
    }
    cout<<dp[n];
    return 0;
}
