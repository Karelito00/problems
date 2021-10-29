#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2;

int dp[MAXn][MAXn][5];
char a1[MAXn];
char a2[MAXn];
bool mark;

int funt(char x){
    if(x == '0')
        return 1;
    return -1;
}

int sol[2001];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a1[i];
    for(int j = 1; j <= n; j++) cin>>a2[j];
    dp[0][0][2] = -1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 1; k <= 3; k++){
                if(dp[i][j][k]){
                    if(!dp[i + 1][j][k + funt(a1[i + 1])])
                        dp[i + 1][j][k + funt(a1[i + 1])] = 1;
                    if(!dp[i][j + 1][k + funt(a2[j + 1])])
                        dp[i][j + 1][k + funt(a2[j + 1])] = 2;
                }
            }
        }
    }
    int aux = 2;
    int cont = n * 2;
    int i = n, j = n;
    while(dp[i][j][aux] != -1){
        sol[cont] = dp[i][j][aux];
        int kk = 0;
        if(dp[i][j][aux] == 1){
            kk = funt(a1[i]);
            i--;
        }
        else{
            kk = funt(a2[j]);
            j--;
        }
        aux -= kk;
        cont--;
    }
    for(int i = 1; i <= 2 * n; i++) cout<<sol[i];
    return 0;
}
