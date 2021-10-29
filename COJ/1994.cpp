#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 97654321;

unordered_map < char , int > id;

vector < int > adya[53];
long long dp[253][253][53];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 26; i++){
        id[i + 'a'] = i;
    }
    for(int i = 0; i < 26; i++){
        id[i + 'A'] = i + 26;
    }
    int u, l, p;
    cin>>u>>l>>p;
    for(int i = 0; i < p; i++){
        string s;
        cin>>s;
        adya[id[s[0]]].push_back(id[s[1]]);
    }
    for(auto x: id){
        if(x.f >= 'a' && x.f <= 'z')
            dp[0][1][x.s] = 1;
        else
            dp[1][0][x.s] = 1;
    }
    for(int i = 0; i <= u; i++){
        for(int j = 0; j <= l; j++){
            if(i == j && i == 0)
                continue;
            for(int k = 0; k <= 51; k++){
                if(dp[i][j][k] == 0) continue;
                for(auto x: adya[k]){
                    if(x >= 0 && x <= 25)
                        dp[i][j + 1][x] = (dp[i][j + 1][x] + dp[i][j][k]) % MOD;
                    else
                        dp[i + 1][j][x] = (dp[i + 1][j][x] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    long long sol = 0;
    for(int i = 0; i <= 51; i++)
        sol = (sol + dp[u][l][i]) % MOD;
    cout<<sol;
    return 0;
}
