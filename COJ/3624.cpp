#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 9;

long long dp[101][101][21];
long long arr[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, r;
    cin>>n>>t>>r;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        arr[i] = arr[i] % r;
        dp[1][i][arr[i]]++;
    }
    for(int i = 1; i < t; i++){
        for(int j = 1; j <= n; j++){
            for(int l = 0; l < r; l++){
                for(int k = j + 1; k <= n; k++)
                    dp[i + 1][k][(l + arr[k]) % r] = (dp[i + 1][k][(l + arr[k]) % r] + dp[i][j][l]) % MOD;
            }
        }
    }
    long long sol = 0;
    for(int i = t; i <= n; i++) sol = (sol + dp[t][i][0]) % MOD;
    cout<<sol;
    return 0;
}
