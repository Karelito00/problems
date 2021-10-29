#include <bits/stdc++.h>

using namespace std;

int mat[21][21];
long long dp[1<<20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    long long best=9999999999;
    for(int mask=(1<<n)-1;mask>=1;mask--){
        if(__builtin_popcount(mask)>k){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int o=0;o<n;o++){
                    if((mask&(1<<o)) && i!=o){
                        if(dp[(mask^(1<<i))]==0)
                            dp[(mask^(1<<i))]=dp[mask]+mat[i][o];
                        else
                            dp[(mask^(1<<i))]=min(dp[(mask^(1<<i))],dp[mask]+mat[i][o]);
                    }
                }
            }
        }
        }
        else if(__builtin_popcount(mask)==k)
            best=min(best,dp[mask]);
    }
    cout<<best;
    return 0;
}
