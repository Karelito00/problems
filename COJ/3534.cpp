#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 166666, MAXm = 1e6;
bool criba[MAXn];
vector < long long > primos;
int table[MAXm + 20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i * i <= MAXn; i++){
        for(int j = i * 2; j <= MAXn; j += i)
            criba[j] = true;
    }
    for(int i = 2; i <= MAXn; i++){
        if(!criba[i])
            primos.push_back(i);
    }
    int tam = primos.size();
    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j< tam; j++){
            if(primos[i] * primos[j] > MAXm) break;
            for(int k = j + 1; k < tam; k++){
                if(primos[i] * primos[j] * primos[k] > MAXm) break;
                table[primos[i] * primos[j] * primos[k]] = 1;
            }
        }
    }
    for(int i = 1; i <= MAXm; i++)
        table[i] += table[i - 1];
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<table[b] - table[a - 1]<<"\n";
    }
    return 0;
}
