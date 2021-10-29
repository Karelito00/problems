#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

int dp[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int p, n;
        cin>>p>>n;
        fill(dp, dp + p + 1, INT_MAX);
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            dp[x] = 1;
            for(int i = x + 1; i <= p; i++)
                if(dp[i - x] != INT_MAX) dp[i] = mn(dp[i], dp[i - x] + 1);
        }
        cout<<dp[p]<<"\n";
    }
    return 0;
}
