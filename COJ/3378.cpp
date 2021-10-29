#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7;

unordered_map < int , int > memo;

int funt(int a){
    if(memo[a] != 0)
        return memo[a];
    int o = a;
    int sum = 0;
    while(o > 0){
        sum += o % 10;
        o /= 10;
    }
    return memo[a] = funt(sum);
}

long long dp[10];
long long up[10];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 9; i++)
        memo[i] = i;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        int aux = funt(x);
        for(int j = 1; j <= 9; j++){
            int ox = funt(aux + j);
            up[ox] = (up[ox] + dp[j]) % MOD;
        }
        up[aux]++;
        for(int j = 1; j <= 9; j++)
            dp[j] = (dp[j] + up[j]) % MOD;
        fill(up + 0, up + 10, 0);
    }
    for(int i = 1; i <= 9; i++)
        cout<<dp[i]<<"\n";
    return 0;
}
