#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7, MAXn = 2e3 + 2;

long long fact[MAXn];
long long pascal[MAXn][MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
    pascal[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
        pascal[i][0] = 1;
    }
    long long sol = 0;
    for(int i = 0; i <= n; i++)
        sol = (sol + ((i % 2 ? -1 : 1) * (fact[n - i] * pascal[n][i] % MOD)) + MOD) % MOD;
    cout<<sol;
    return 0;
}
