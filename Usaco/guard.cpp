#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long ll;

struct cow{
    ll h;
    ll p;
    ll f;
}arr[22];

long long dp[(1 << 20) + 5];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll mark;
    cin>>n>>mark;
    for(int i = 0; i < n; i++)
        cin>>arr[i].h>>arr[i].p>>arr[i].f;

    int sol = -1;
    fill(dp, dp + (1 << n), -1);
    for(int i = 0; i < n; i++)
        dp[(1 << i)] = arr[i].f;
    for(int mask = 0; mask < (1 << n); mask++){
        ll alt = 0;
        for(int i = 0; i < n; i++){
            if(!(mask&(1 << i)))
                dp[(mask^(1 << i))] = mx(dp[(mask^(1 << i))], mn(dp[mask] - arr[i].p, arr[i].f));
            else
                alt += arr[i].h;
        }
        if(dp[mask] >= 0 && alt >= mark)
            sol = mx(sol, dp[mask]);
    }
    if(sol >= 0)
        cout<<sol;
    else
        cout<<"Mark is too tall";
    return 0;
}
