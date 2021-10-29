#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e7 + 2, MAXp = 7e5;
bool criba[MAXn];
int primos[MAXp];
int table[MAXn][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    for(int i = 2; i * i <= MAXn - 2; i++){
        for(int j = i * i; j <= MAXn - 2; j += i)
            criba[j] = true;
    }
    for(int i = 2; i <= MAXn - 2; i++){
        if(!criba[i])
            primos[++n] = i;
    }
    for(int i = 1; i <= n; i++){
        int aux = primos[i];
        while(aux > 0){
            table[i][aux % 10] = 1;
            aux /= 10;
        }
        for(int j = 0; j <= 10; j++)
            table[i][j] += table[i - 1][j];
    }
    int q;
    cin>>q;
    while(q--){
        int a, b, d;
        cin>>a>>b>>d;
        if(a > b) swap(a, b);
        int fin = upper_bound(primos + 1, primos + n + 1, b) - primos - 1;
        int ini = lower_bound(primos + 1, primos + n + 1, a) - primos;
        cout<<table[fin][d] - table[ini - 1][d]<<"\n";
    }
    return 0;
}
