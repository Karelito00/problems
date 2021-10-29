#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define par pair < int ,int >

using namespace std;

int const MAXn = 3e4 + 10;
unordered_map < int , int > mapa;
unordered_map < int , int > mapa2;

struct trio{
    int id;
    int salario;
    int altura;
    bool operator < (const trio &var) const {
        return (var.altura != altura ? var.altura < altura : var.salario < salario);
    }
}arr[MAXn];

int padre[MAXn];
int dist[MAXn];
vector < int > adya[MAXn];

int DFS(int v, int p){
    padre[v] = p;
    int con = 1;
    for(auto to: adya[v]){
        if(to != p)
            con += DFS(to, v);
    }
    dist[v] = con - 1;
    return con;
}

struct cmp{
    bool operator () (const par &a,const par &b) const {
        return a.f < b.f;
    }
};

set < par , cmp > salid;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        for(int i = 1; i <= n; i++){
            int idx, sal, alt;
            cin>>idx>>sal>>alt;
            mapa[i] = idx;
            mapa2[idx] = i;
            arr[i] = trio{i, sal, alt};
        }
        sort(arr + 1, arr + n + 1);
        int pres = arr[1].id;
        salid.insert(mp(arr[1].salario, arr[1].id));
        for(int i = 2; i <= n; i++){
            int nid = arr[i].id;
            par k = *salid.upper_bound(mp(arr[i].salario, INT_MAX));
            adya[nid].push_back(k.s);
            adya[k.s].push_back(nid);
            salid.insert(mp(arr[i].salario, arr[i].id));
        }
        DFS(pres, 0);
        while(q--){
            int iddd;
            cin>>iddd;
            int newid = mapa2[iddd];
            cout<<mapa[padre[newid]]<<" "<<dist[newid]<<"\n";
        }
        mapa.clear();
        mapa2.clear();
        for(int i = 1; i <= n; i++)
            adya[i].clear();
        salid.clear();
    }
    return 0;
}
