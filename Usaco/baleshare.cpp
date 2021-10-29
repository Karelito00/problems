#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)

using namespace std;

const int MAXS = 700;
bool dp[21][MAXS+101][MAXS+101];
int n;

int main(){

    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);

    dp[0][0][0] = true;
    int sum = 0;

    cin>>n;
    for(int i=0;i<n;i++){
        int bale;
        cin>>bale;
        sum += bale;
        for(int j=0;j<MAXS;j++){
            for(int k=0;k<MAXS;k++){
                if(dp[i][j][k]){
                    dp[i+1][j][k] = true;
                    dp[i+1][j+bale][k] = true;
                    dp[i+1][j][k+bale] = true;
                }
            }
        }
    }
    int sol = INT_MAX;
    for(int i=0;i<MAXS;i++)
        for (int j=0;j<MAXS;j++)
            if(dp[n][i][j])
                sol = mn(sol, mx(i, mx(j, sum - i - j)));
    cout<<sol<<"\n";
    return 0;
}
