#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int funt(char x){
    if(x >= 'a' && x <= 'z')
        return 1;
    if(x >= '0' && x <='9')
        return 2;
    return 3;
}

long long dp[51][4];

int main()
{
    freopen("dashapass.in","r",stdin);
    freopen("dashapass.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        dp[i][1] = dp[i][2] = dp[i][3] = INT_MAX;
    }
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        int tm = s.size();
        for(int j = 0; j < tm; j++){
            int aux = funt(s[j]);
            dp[i][aux] = mn(dp[i][aux], mn(j, tm - j));
        }
    }
    long long sol = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                sol = mn(sol, dp[i][1] + dp[j][2] + dp[k][3]);
                sol = mn(sol, dp[i][1] + dp[j][3] + dp[k][2]);
                sol = mn(sol, dp[i][2] + dp[j][1] + dp[k][3]);
                sol = mn(sol, dp[i][2] + dp[j][3] + dp[k][1]);
                sol = mn(sol, dp[i][3] + dp[j][1] + dp[k][2]);
                sol = mn(sol, dp[i][3] + dp[j][2] + dp[k][1]);
            }
        }
    }
    cout<<sol;
    return 0;
}
