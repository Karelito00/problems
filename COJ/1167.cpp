#include <bits/stdc++.h>

using namespace std;

string z[17];
int dp[1<<16][17];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int y=0;y<n;y++){
            cin>>z[y];
        }
        int sol=0;
        for(int u=0;u<n;u++){
            dp[1<<u][u]=z[u].size();
            sol=max(sol,dp[1<<u][u]);
        }
        for(int mask=0;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    char x=z[i][z[i].size()-1];
                    for(int j=0;j<n;j++){
                        char y=z[j][0];
                        if(!(mask&(1<<j)) && x==y){
                            int l=mask|(1<<j);
                            dp[l][j]=max(dp[l][j],dp[mask][i]+(int)z[j].size());
                            sol=max(sol,dp[l][j]);
                        }
                    }
                }
            }
        }
        cout<<sol<<"\n";
        memset(dp,0,sizeof dp);
    }
    return 0;
}
