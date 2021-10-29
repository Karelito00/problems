#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;
int obj[1001];
long long dp[3001];
int suma;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k%3==0)
            obj[i]=3;
        else
            obj[i]=k%3;
        suma+=obj[i];
    }
    dp[0]=1;
    for(int u=0;u<n;u++){
        int val=obj[u];
        for(int h=suma;h>=val;h--){
            if(dp[h]==0){
                if(dp[h-val]!=0)
                    dp[h]=dp[h-val];
            }
            else{
                if(dp[h-val]!=0)
                    dp[h]=(dp[h-val]+dp[h])%MOD;
            }
        }
    }
    long long cant=0;
    for(int h=1;h<=suma;h++){
        if(h%3==0)
            cant=(cant+dp[h])%MOD;
    }
    cout<<cant;

    return 0;
}

