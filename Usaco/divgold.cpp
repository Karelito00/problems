#include <bits/stdc++.h>

using namespace std;

int dp[250001];
int obj[251];

int main()
{
    freopen("divgold.in","r",stdin);
    freopen("divgold.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int suma=0;
    for(int i=0;i<n;i++){
        cin>>obj[i];
        suma+=obj[i];
    }
    int jh=suma;
    suma/=2;
    dp[0]=1;
    int best=0;
    for(int u=0;u<n;u++){
        int k=obj[u];
        for(int y=suma;y>=k;y--){
            if(dp[y]==0){
                if(dp[y-k]!=0){
                    dp[y]=dp[y-k];
                    best=max(best,y);
                }
            }
            else{
                if(dp[y-k]!=0){
                    dp[y]=(dp[y]+dp[y-k])%1000000;
                    best=max(best,y);
                }
            }
        }
    }
    int hy=0,sol=0;
    hy=jh-best-best;
    sol=dp[best];
    cout<<hy<<"\n"<<sol;
    return 0;
}
