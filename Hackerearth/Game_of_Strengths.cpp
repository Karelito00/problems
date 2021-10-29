#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long z[100001];

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
        long long suma = 0;
        for(int i=0;i<n;i++){
            cin>>z[i];
            suma = (suma + z[i]) % MOD;
        }
        sort(z,z+n);
        long long total = 0;
        for(int i=0;i<n-1;i++){
            long long h = (z[i] * (n-i-1)) % MOD;
            suma = ((suma - z[i]) + MOD) % MOD;
            total = (total + (suma - h + MOD)) % MOD % MOD;
        }
        cout<<(total * z[n-1]) % MOD<<"\n";
    }
    return 0;
}
