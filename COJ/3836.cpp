#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 10, lg = log2(MAXn) + 3;

map < long long , int > mapa;

struct par{
    int ini;
    int fin;
    bool operator < (const par &var) const {
        if(var.ini != ini)
            return var.ini > ini;
        return var.fin > fin;
    }
}ran[MAXn];

int RMQ[MAXn][lg];

int sol(int a, int b){
    int loga = log2(b - a + 1);
    return mn(RMQ[a][loga], RMQ[b - (1<<loga) + 1][loga]);
}

int con;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    long long suma = 0;
    mapa[0] = true;
    for(int i = 1; i <= n; i++){
        long long x;
        cin>>x;
        suma += x;
        if(mapa.find(suma) != mapa.end())
            ran[++con] = par{mapa[suma], i};
        mapa[suma] = i + 1;
    }
    sort(ran + 1, ran + con + 1);
    for(int i = 1; i <= con; i++)
        RMQ[i][0] = ran[i].fin;
    for(int e = 1; (1<<e) <= con; e++){
        for(int i = 1; i + (1<<e) - 1 <= con; i++)
            RMQ[i][e] = mn(RMQ[i][e - 1], RMQ[i + (1<<(e - 1))][e - 1]);
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        if(con == 0){
            cout<<"NO\n";
            continue;
        }
        int posf = upper_bound(ran + 1, ran + con + 1, par{b, INT_MAX}) - ran - 1;
        int posi = upper_bound(ran + 1, ran + con + 1, par{a - 1, INT_MAX}) - ran;
        if(posf < 1 || posi > con || posi > posf){
            cout<<"NO\n";
            continue;
        }
        cout<<(sol(posi, posf) <= b ? "YES" : "NO")<<"\n";
    }
    return 0;
}
