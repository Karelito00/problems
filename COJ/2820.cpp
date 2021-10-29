#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 5;

long long ABI[4][MAXn];
int arr[MAXn];
map < int , int > mapa;
int con;

void update(int id, int pos, long long val){
    while(pos <= con){
        ABI[id][pos] += val;
        pos += (pos&-pos);
    }
}

long long query(int id, int pos){
    long long suma = 0;
    while(pos >= 1){
        suma += ABI[id][pos];
        pos -= (pos&-pos);
    }
    return suma;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            mapa[arr[i]];
        }
        for(auto x: mapa)
            mapa[x.f] = ++con;
        for(int i = 1; i <= n; i++){
            for(int j = 2; j >= 1; j--){
                long long aux = query(j, con - mapa[arr[i]]);
                update(j + 1, con - mapa[arr[i]] + 1, aux);
            }
            update(1, con - mapa[arr[i]] + 1, 1);
        }
        cout<<query(3, con)<<"\n";
        mapa.clear();
        for(int i = 1; i <= 3; i++)
            fill(ABI[i] + 1, ABI[i] + con + 1, 0);
        con = 0;
    }
    return 0;
}
