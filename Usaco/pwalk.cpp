#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second

using namespace std;

int const MAXn = 1e3 + 10, loga = log2(MAXn) + 3;

vector < pair < int , int > > adya[MAXn];
int n, q;
int dist[MAXn];
int lvl[MAXn];
int lca[MAXn][loga];

void bfs(){
     queue < int > cola;
     cola.push(1);
     lvl[1] = 1;
     while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(auto to: adya[v]){
            if(lvl[to.f])
                continue;
            lvl[to.f] = lvl[v] + 1;
            lca[to.f][0] = v;
            dist[to.f] = dist[v] + to.s;
            cola.push(to.f);
        }
     }
}

void build_LCA(){
     for(int e = 1; (1 << e) < n; e++){
        for(int i = 2; i <= n; i++){
            if(lvl[i] <= (1 << e)) continue;
            lca[i][e] = lca[lca[i][e - 1]][e - 1];
        }
     }
}

int query(int a, int b){
    if(lvl[a] < lvl[b])
        swap(a, b);
    int lg = log2(lvl[a] - 1);
    for(int i = lg; i >= 0; i--)
        if(lvl[lca[a][i]] >= lvl[b]) a = lca[a][i];
    if(a == b)
        return a;
    lg = log2(lvl[a] - 1);
    for(int i = lg; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}
int main(){

    freopen("pwalk.in","r",stdin);
    freopen("pwalk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;;
        adya[n1].push_back(mp(n2, w));
        adya[n2].push_back(mp(n1, w));
    }
    bfs();
    build_LCA();
    for(int i = 0; i < q; i++){
        int a, b;
        cin>>a>>b;
        int l = query(a,b);
        cout<<dist[a] + dist[b] - (2 * dist[l])<<"\n";
    }
    return 0;
}
