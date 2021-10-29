#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7, MAXn = (1 << 12) + 2;

long long dp[502][MAXn];
int wins[502];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string player;
    cin>>player;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 12; j++){
            char x;
            cin>>x;
            if(x >= player[j])
                wins[i] |= (1 << j);
        }
    }
    for(int i = 1; i <= n; i++)
        dp[i][wins[i]]++;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < MAXn - 2; j++){
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            dp[i + 1][j | wins[i + 1]] = (dp[i + 1][j | wins[i + 1]] + dp[i][j]) % MOD;
        }
    }
    long long sol = 0;
    for(int i = 0; i < MAXn - 2; i++){
        if(__builtin_popcount(i) > 6)
            sol = (sol + dp[n][i]) % MOD;
    }
    cout<<sol;
    return 0;
}
