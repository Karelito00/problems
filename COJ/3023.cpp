#include <bits/stdc++.h>
#define mx(a, b) (a > b ? a : b)

using namespace std;

long long const MOD = 1e15;

long double dp[102][10][10];
long double dp2[102][10][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i <= 9; i++){
        dp[1][i][i] = 1;
        dp2[1][i][i] = 1;
    }
    for(int i = 1; i <= 99; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = j; k <= 9; k++){
                if(!dp[i][j][k]) continue;
                if(j >= 1) dp[i + 1][j - 1][k] = (dp[i][j][k] + dp[i + 1][j - 1][k]);
                if(j < 9) dp[i + 1][j + 1][mx(k, j + 1)] = (dp[i][j][k] + dp[i + 1][j + 1][mx(k, j + 1)]);
                dp[i + 1][j][k] = (dp[i][j][k] + dp[i + 1][j][k]);
            }
        }
    }
    for(int i = 1; i <= 99; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = j; k <= 9; k++){
                for(int u = 0; u <= 9; u++)
                    dp2[i + 1][u][mx(u, k)] = (dp2[i][j][k] + dp2[i + 1][u][mx(u, k)]);
            }
        }
    }
    int k, n;
    while(cin>>k>>n){
        long double total = 0, suma = 0;
        for(int i = 0; i <= k; i++){
            for(int j = i; j <= k; j++){
                suma += dp[n][i][j];
                total += dp2[n][i][j];
            }
        }
        cout<<fixed<<setprecision(5)<<(suma / total) * 100<<"\n";
    }
    return 0;
}
