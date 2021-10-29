#include <bits/stdc++.h>

using namespace std;

int arr[21][21];
long long dp[(1<<20)+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    dp[0] = 1;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<(1<<n);i++)
            dp[i] = 0;
        for(int mask=0;mask<(1<<n);mask++){
            int bits = __builtin_popcount(mask);
            for(int i=0;i<n;i++){
                if(arr[bits][i] && !(mask&(1<<i)))
                    dp[(mask | (1<<i))] += dp[mask];
            }
        }
        cout<<dp[(1<<n)-1]<<"\n";
    }
    return 0;
}
