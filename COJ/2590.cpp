#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, MOD = 5e6;

long long ABI[52][MAXn];

void update(int id, long long val, int pos){
    while(pos <= MAXn - 2){
        ABI[id][pos] = (ABI[id][pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

long long query(int pos, int id){
    long long suma = 0;
    while(pos >= 1){
        suma = (suma + ABI[id][pos]) % MOD;
        pos -= (pos&-pos);
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        for(int j = k - 1; j >= 1; j--){
            long long aux = query(num - 1, j);
            update(j + 1, aux, num);
        }
        update(1, 1, num);
    }
    cout<<query(MAXn - 2, k);
    return 0;
}
