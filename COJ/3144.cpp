#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e2 + 1, MAXp = 1e3 + 260;

struct par{
    int peso;
    int benef;
    bool operator < (const par& var) const {
        return (var.peso != peso ? var.peso > peso : var.benef < benef);
    }
}arr[MAXn];

long long dp[MAXp];

int main()
{
    freopen("cheese.in","r",stdin);
    freopen("cheese.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, pt, t;
    cin>>n>>pt>>t;

    for(int i = 0; i < n; i++)
        cin>>arr[i].benef>>arr[i].peso;
    sort(arr, arr + n);
    long long sol = 0;
    for(int u = 0; u < 2; u++){
        fill(dp, dp + pt + 1, 0);
        for(int i = 0; i < n; i++){
            if(u == 0 && arr[i].peso >= t) break;
            int pes = (u ? (arr[i].peso * 4 / 5) : arr[i].peso);
            dp[pes] = mx(dp[pes], arr[i].benef);
            for(int j = pes; j <= pt; j++)
                if(dp[j - pes]) dp[j] = mx(dp[j - pes] + arr[i].benef, dp[j]);
        }
        if(u == 0)
            sol = *max_element(dp, dp + pt + 1);
    }
    for(int i = 1; i <= pt; i++)
        dp[i] = mx(dp[i], dp[i - 1]);
    int l = lower_bound(arr, arr + n, par{t, INT_MAX}) - arr;
    for(; l < n; l++)
        sol = mx(sol, dp[pt - arr[l].peso] + arr[l].benef);
    cout<<sol;
    return 0;
}
