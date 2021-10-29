#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
long long arrx[100001];
long long arry[100001];
long long arrz[100001];
long long acx[100001];
long long acz[100001];
int x,y,z;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        for(int i=0;i<x;i++){
            cin>>arrx[i];
        }
        for(int i=0;i<y;i++){
            cin>>arry[i];
        }
        for(int i=0;i<z;i++){
            cin>>arrz[i];
        }
        sort(arrx,arrx + x);
        sort(arrz,arrz + z);
        acx[0] = arrx[0];
        acz[0] = arrz[0];
        for(int i=1;i<x;i++){
            acx[i] = (arrx[i] + acx[i-1]) % MOD;
        }
        for(int i=0;i<z;i++){
            acz[i] = (arrz[i] + acz[i-1]) % MOD;
        }
        long long total = 0;
        for(int u=0;u<y;u++){
           int pos = upper_bound(arrx, arrx + x, arry[u]) - arrx;
           long long num = (acx[pos-1] + ((arry[u] * pos) % MOD)) % MOD;
           pos = upper_bound(arrz, arrz + z, arry[u]) - arrz;
           long long num2 = (acz[pos-1] + ((arry[u] * pos) % MOD)) % MOD;
           total = (total + ( ( num * num2 ) % MOD ) ) % MOD;
        }
        cout<<total<<"\n";
    }
    return 0;
}
//Numbers Theory + Binary search
