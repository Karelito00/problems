#include <bits/stdc++.h>

using namespace std;

int const MAXp = 15e3 + 2, MAXn = 1e6 + 2;

int con;
int primos[MAXp];
bool criba[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 2; i <= MAXn - 2; i++){
        if(!criba[i]){
            primos[++con] = i;
            if(con == 15000) break;
        }
        for(long long j = i * i; j <= MAXn - 2; j += i)
            criba[j] = true;
    }
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<primos[k]<<"\n";
    }
    return 0;
}
