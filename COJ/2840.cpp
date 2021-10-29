#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < int , long long > dp[37];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    dp[1][-1]++;
    dp[1][1]++;
    for(int i = 1; i < n; i++){
        for(auto x: dp[i]){
            dp[i + 1][x.f + (i + 1)] += x.s;
            dp[i + 1][x.f - (i + 1)] += x.s;
        }
    }
    cout<<dp[n][0]/2;
    return 0;
}
