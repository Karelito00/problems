#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

long long arr[MAXn];
long long dp[MAXn];
long long aux[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        long long sum = 0;
        long long minm_sum = 0;
        long long maxm = -(1LL * INT_MAX * INT_MAX);
        for(int i = 1; i <= n; i++){
            sum += arr[i];
            dp[i] = sum;
            aux[i] = mx(aux[i - 1], sum);
            maxm = mx(maxm, sum - minm_sum);
            minm_sum = mn(minm_sum, sum);
        }
        if(k > 1){
            for(int i = 0; i < n; i++)
                maxm = mx(maxm, (sum - dp[i]) + (sum * (k - 2)) + aux[n]);
            for(int i = 0; i < n; i++)
                maxm = mx(maxm, dp[n] - dp[i] + aux[i]);
        }
        cout<<maxm<<"\n";
    }
    return 0;
}
