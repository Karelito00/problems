#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct combo{
    string s;
    int tam;
    bool operator < (const combo &var) const {
        return var.tam < tam;
    }
}arr[21];

int cost[21][16];
vector < int > lcm[21][21];
int dp[1002][21];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tt;
    cin>>n>>tt;
    for(int i = 1; i <= n; i++){
        cin>>arr[i].s;
        arr[i].tam = arr[i].s.size();
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            for(int k = 0; k <= arr[i].tam - arr[j].tam; k++){
                bool yes = true;
                for(int k2 = 0; k2 < arr[j].tam; k2++)
                    if(arr[i].s[k + k2] != arr[j].s[k2]){
                        yes = false;
                        break;
                    }
                if(yes)
                    cost[i][k + arr[j].tam]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= arr[i].tam; j++)
            cost[i][j] += cost[i][j - 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            lcm[i][j].push_back(0);
            for(int k = mx(0, arr[i].tam - arr[j].tam); k < arr[i].tam; k++){
                bool yes = true;
                for(int k2 = 0; k2 + k < arr[i].tam; k2++){
                    if(arr[i].s[k + k2] != arr[j].s[k2]){
                        yes = false;
                        break;
                    }
                }
                if(yes)
                    lcm[i][j].push_back(arr[i].tam - k);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        dp[arr[i].tam][i] = cost[i][arr[i].tam];
    for(int i = 1; i <= tt; i++){
        for(int j = 1; j <= n; j++){
            if(!dp[i][j]) continue;
            for(int k = 1; k <= n; k++){
                for(auto x: lcm[j][k]){
                    if(i + arr[k].tam - x <= tt)
                        dp[i + arr[k].tam - x][k] = mx(dp[i + arr[k].tam - x][k], dp[i][j] + (cost[k][arr[k].tam] - cost[k][x]));
                }
            }
        }
    }
    int sol = 0;
    for(int i = 1; i <= n; i++)
        sol = mx(sol, dp[tt][i]);
    cout<<sol;
    return 0;
}
