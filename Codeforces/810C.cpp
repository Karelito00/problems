#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long z[300001];
long long pot[300001];

void po(int n){
    int sum = 1;
    pot[0]=1;
    while(n>0){
        pot[sum] = (pot[sum-1] * 2) % MOD;
        sum++;
        n--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    po(300000);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    sort(z,z+n);
    long long sumamn = 0;
    long long sumamx = 0;
    for(int i=0;i<n;i++){
        sumamn = (sumamn + ((pot[n-i-1]*z[i])%MOD)) % MOD;
        sumamx = (sumamx + (((pot[i])*z[i])%MOD)) % MOD;
    }
    cout<<((sumamx-sumamn)+MOD) % MOD;
    return 0;
}
