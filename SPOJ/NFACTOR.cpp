#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e6 + 2;

bool criba[MAXn];
vector < int > primos;
int table[MAXn][11];

int fact(int x){
    int aux = x;
    int con = 0;
    for(auto nn: primos){
        if(nn * nn > x) break;
        if(aux % nn) continue;
        con++;
        while(aux % nn == 0)
            aux /= nn;
    }
    if(aux != 1) con++;
    return con;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i * i <= MAXn; i++){
        if(!criba[i])
            primos.push_back(i);
        for(int j = i * i; j <= MAXn; j += i)
            criba[j] = true;
    }
    for(int i = 1; i <= MAXn - 2; i++){
        int aux = fact(i);
        if(aux <= 10)
            table[i][aux]++;
            for(int j = 0; j <= 10; j++)
                table[i][j] += table[i - 1][j];
    }
    int t;
    cin>>t;
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;
        cout<<table[b][k] - table[a - 1][k]<<"\n";
    }
    return 0;
}
