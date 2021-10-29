#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 3, loga = log2(MAXn) + 2;

vector < int > adya[MAXn];
int subt[MAXn];
int level[MAXn];
int from[MAXn];

void DFS(int v, int p){
    int cant = 1;
    for(auto to: adya[v]){
        if(to == p || level[to] != -1) continue;
        DFS(to, v);
        cant += subt[to];
    }
    subt[v] = cant;
}

int centroid(int v, int p, int w){
    for(auto to: adya[v]){
        if(to == p || level[to] != -1) continue;
        if(subt[to] > w / 2)
            return centroid(to, v, w);
    }
    return v;
}

void centroid_decomposition(int v, int lvl, int p){
    DFS(v, -1);
    int root = centroid(v, p, subt[v]);
    if(p == -1) p = root;
    from[root] = p;
    level[root] = lvl;
    for(auto to: adya[root]){
        if(level[to] != -1) continue;
        centroid_decomposition(to, lvl + 1, root);
    }
}

int lvl[MAXn];
int padre[MAXn][loga];
int sol[MAXn];
int n, q;

void DFS1(int v, int p){
    for(auto to : adya[v]){
        if(to != p){
            lvl[to] = lvl[v] + 1;
            padre[to][0] = v;
            DFS1(to, v);
        }
    }
}

void preparar(){
    lvl[1] = 1;
    DFS1(1, -1);
    for(int e = 1; (1<<e) < n; e++){
        for(int i = 1; i <= n; i++){
            padre[i][e] = padre[padre[i][e - 1]][e - 1];
        }
    }
}

int LCA(int a, int b){
    if(lvl[a] < lvl[b]) swap(a, b);
    int lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--){
        if(lvl[padre[a][i]] >= lvl[b])
            a = padre[a][i];
    }
    if(a == b) return a;
    lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--){
        if(padre[a][i] != padre[b][i]){
            a = padre[a][i];
            b = padre[b][i];
        }
    }
    return padre[a][0];
}

int dist(int a, int b){
    int lca = LCA(a, b);
    return lvl[a] + lvl[b] - (2 * lvl[lca]);
}

void update(int v){
    int x = v;
    while(1){
        sol[x] = min(sol[x], dist(x, v));
        if(from[x] == x)
            break;
        x = from[x];
    }
}

int query(int v){
    int x = v;
    int soll = INT_MAX;
    while(1){
        soll = min(soll, dist(x, v) + sol[x]);
        if(from[x] == x) break;
        x = from[x];
    }
    return soll;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    preparar();
    fill(sol + 1, sol + n + 1, MAXn);
    fill(level + 1, level + n + 1, -1);
    centroid_decomposition(1, 0, -1);
    update(1);
    while(q--){
        int type, v;
        cin>>type>>v;
        if(type == 1)
            update(v);
        else
            cout<<query(v)<<"\n";
    }
    return 0;
}
