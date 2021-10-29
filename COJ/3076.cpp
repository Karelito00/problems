#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define MAX 999999999

using namespace std;

int const MAXn = 1e3 + 10;

int arr[MAXn];
long long dp[MAXn][MAXn][2];

queue < pair < int , int > > cola;
bool marc[MAXn][MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j - 1 <= n; j++){
            dp[i][j][0] = MAX;
            dp[i][j][1] = MAX;
        }
    }
    dp[2][1][1] = arr[2];
    cola.push(mp(2,1));
    while(!cola.empty()){
        int index = cola.front().f;
        int salto = cola.front().s;
        cola.pop();
        marc[index][salto] = false;
        int nix = index + salto + 1;
        if(nix <= n && dp[nix][salto + 1][1] > dp[index][salto][1] + arr[nix]){
            dp[nix][salto + 1][1] = dp[index][salto][1] + arr[nix];
            if(!marc[nix][salto + 1] && nix != n){
                cola.push(mp(nix, salto + 1));
                marc[nix][salto + 1] = true;
            }
        }
        if(nix <= n && dp[nix][salto + 1][1] > dp[index][salto][0] + arr[nix]){
            dp[nix][salto + 1][1] = dp[index][salto][0] + arr[nix];
            if(!marc[nix][salto + 1] && nix != n){
                cola.push(mp(nix, salto + 1));
                marc[nix][salto + 1] = true;
            }
        }
        nix = index - salto;
        if(nix >= 1 && dp[nix][salto][0] > dp[index][salto][1] + arr[nix]){
            dp[nix][salto][0] = dp[index][salto][1] + arr[nix];
            if(!marc[nix][salto] && nix != n){
                cola.push(mp(nix, salto));
                marc[nix][salto] = true;
            }
        }
        if(nix >= 1 && dp[nix][salto][0] > dp[index][salto][0] + arr[nix]){
            dp[nix][salto][0] = dp[index][salto][0] + arr[nix];
            if(!marc[nix][salto] && nix != n){
                cola.push(mp(nix, salto));
                marc[nix][salto] = true;
            }
        }
    }
    int minm = MAX;
    for(int i = 1; i <= n - 1; i++)
        minm = mn(minm, dp[n][i][1]);
    cout<<minm;
    return 0;
}
