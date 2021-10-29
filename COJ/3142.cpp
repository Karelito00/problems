#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < int , int > par;

bool dp[102][10003];
bool dp2[102][10003];
int besie[102][102];
int elsie[102][102];


int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int n1, n2, b, e;
        cin>>n1>>n2>>b>>e;
        besie[n1][n2] = b;
        elsie[n1][n2] = e;
    }
    dp[1][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            if(!dp[i][j]) continue;
            for(int k = i + 1; k <= n; k++){
                if(besie[i][k]) dp[k][j + besie[i][k]] = true;
            }
        }
    }
    dp2[1][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            if(!dp2[i][j]) continue;
            for(int k = i + 1; k <= n; k++){
                if(elsie[i][k]) dp2[k][j + elsie[i][k]] = true;
            }
        }
    }
    for(int i = 1; i <= 10000; i++){
        if(dp[n][i] && dp2[n][i]){
            cout<<i;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
