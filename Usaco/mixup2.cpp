#include <bits/stdc++.h>

using namespace std;
int z[17];
long long sol;
long long dp[1<<17][17];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mixup2.in","r",stdin);
    freopen("mixup2.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>z[i];
    for(int i=0;i<n;i++){
        dp[1<<i][i]=1;
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(int y=0;y<n;y++){
                    if(!(mask&(1<<y)) && abs(z[u]-z[y])>k)
                        dp[(mask|(1<<y))][y]+=dp[mask][u];
                }
            }
        }
    }
    for(int h=0;h<n;h++){
        sol+=dp[(1<<n)-1][h];
    }
    cout<<sol;
    return 0;
}
