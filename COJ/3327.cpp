#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long tt = 5;

long long dp[19][19];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1][0] = 5;
    dp[1][1] = 4;
    for(int d = 1; d <= 17; d++){
        for(int e = 0; e <= d; e++){
            dp[d + 1][e] += (dp[d][e] * tt);
            dp[d + 1][e + 1] += (dp[d][e] * tt);
        }
    }
    dp[1][1]++;
    for(int d = 1; d <= 18; d++){
        for(int e = 0; e <= d; e++)
            dp[d][e] *= (long long)2;
    }
    dp[1][1]--;
    int e, o;
    while(1){
        cin>>e>>o;
        if(!e && !o) return 0;
        cout<<dp[e + o][e]<<"\n";
    }
    return 0;
}
