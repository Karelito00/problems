#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

queue < long long > cola;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, d;
    cin>>k>>d;
    long long suma = 2;
    long long val = 1;
    cola.push(1);
    cola.push(2);
    for(int i=2;i<=d;i++){
        if(i<=k)
            val = suma;
        else{
            val = (suma - cola.front() + MOD) % MOD;
            cola.pop();
        }
        suma = (suma + val) % MOD;
        cola.push(suma);
    }
    cout<<val%MOD;
    return 0;
}
