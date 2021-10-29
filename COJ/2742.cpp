#include <bits/stdc++.h>
#define MOD 1000009

using namespace std;

long long pascal[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pascal[0][0]=1;
    for(int i=1;i<=1000;i++){
        for(int j=0;j<=i;j++){
            pascal[i][j]=(pascal[i-1][j]+pascal[i-1][j-1])%MOD;
        }
    }
    int c;
    cin>>c;
    while(c--){
        int n,k;
        cin>>n>>k;
        long long suma=0;
        for(int i=k;i<=n;i++){
            long long t = pascal[i-1][k-1];
            suma = ( suma + ( ( i * t ) % MOD ) ) % MOD;
        }
        cout<<suma%MOD<<"\n";
    }
    return 0;
}
