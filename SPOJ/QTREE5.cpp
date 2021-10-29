#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 4, loga = log2(MAXn) + 2;

vector < int > adya[MAXn];
int lvl[MAXn];
int padre[MAXn][loga];
int n;

void DFS(int v, int p){
    for(auto to: adya[v]){
        if(to == p) continue;
        lvl[to] = lvl[v] + 1;
        padre[to][0] = v;
        DFS(to, v);
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

void prepar(){
    lvl[1] = 1;
    DFS(1, -1);
    for(int e = 1; (1<<e) < n; e++){
        for(int i = 1; i <= n; i++)
            padre[i][e] = padre[padre[i][e - 1]][e - 1];
    }
}

int dist(int a, int b){
    int lca = LCA(a, b);
    return lvl[a] + lvl[b] - (2 * lvl[lca]);
}

int subt[MAXn];
bool level[MAXn];
int from[MAXn];
bool arr[MAXn];
int dp[MAXn][loga];

void DFS1(int v, int p){
    int cant = 1;
    for(auto to: adya[v]){
        if(to == p || level[to]) continue;
        DFS1(to, v);
        cant += subt[to];
    }
    subt[v] = cant;
}

int centroid(int v, int &w, int p){
    for(auto to: adya[v]){
        if(to == p || level[to]) continue;
        if(subt[to] > w / 2)
            return centroid(to, w, v);
    }
    return v;
}

void centroid_decomposition(int v, int p){
    DFS1(v, -1);
    int root = centroid(v, subt[v], -1);
    level[root] = true;
    from[root] = (p == -1 ? root : p);
    for(auto to: adya[root]){
        if(level[to]) continue;
        centroid_decomposition(to, root);
    }
}

multiset < int > sol[MAXn];

int query(int v){
    int x = v;
    int best = MAXn;
    while(1){
        best = min(best, dist(v, x) + *sol[x].begin());
        if(from[x] == x) break;
        x = from[x];
    }
    return (best == MAXn ? -1 : best);
}

void update_false(int v){
    int x = v;
    while(1){
        sol[x].insert(dist(v, x));
        if(from[x] == x) break;
        x = from[x];
    }
    arr[v] = true;
}

void update_true(int v){
    int x = v;
    while(1){
        sol[x].erase(sol[x].find(dist(v, x)));
        if(from[x] == x) break;
        x = from[x];
    }
    arr[v] = false;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i < n; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    prepar();
    centroid_decomposition(1, -1);
    for(int i = 1; i <= n; i++)
        sol[i].insert(MAXn);
    int q;
    cin>>q;
    while(q--){
        bool type;
        int v;
        cin>>type>>v;
        if(type)
            cout<<query(v)<<"\n";
        else
            (arr[v] ? update_true(v) : update_false(v));
    }
    return 0;
}
