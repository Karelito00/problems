#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define mx(a, b) (a > b ? a : b)

using namespace std;

int const MAXn = 2e3 + 2;

pair < int , int > arr[MAXn];
int dp[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p, n;
    cin>>p>>n;
    long long sol = 0;
    for(int i = 1; i <= n; i++)
        cin>>arr[i].f>>arr[i].s;
    for(int i = 1; i <= n; i++){
        for(int j = p; j > arr[i].f; j--){
            if(dp[j - arr[i].f])
                dp[j] = mx(dp[j], dp[j - arr[i].f] + arr[i].s);
        }
        dp[arr[i].f] = mx(arr[i].f, arr[i].s);
    }
    for(int i = 1; i <= p; i++)
        sol = mx(sol, dp[i]);
    cout<<sol;
    return 0;
}
