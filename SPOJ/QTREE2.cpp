#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e4 + 2, loga = log2(MAXn) + 2;

vector < pair < int , long long > > adya[MAXn];
int lvl[MAXn];
long long dist[MAXn];
int padre[MAXn][loga];

void DFS(int v, int p){
    for(auto to: adya[v]){
        if(to.f == p) continue;
        padre[to.f][0] = v;
        dist[to.f] = dist[v] + to.s;
        lvl[to.f] = lvl[v] + 1;
        DFS(to.f, v);
    }
}

int LCA(int a, int b){
    if(lvl[b] > lvl[a]) swap(a, b);
    int lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--)
        if(lvl[padre[a][i]] >= lvl[b])
            a = padre[a][i];
    if(a == b)
        return a;
    lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--){
        if(padre[a][i] != padre[b][i]){
            a = padre[a][i];
            b = padre[b][i];
        }
    }
    return padre[a][0];
}

int find_kth(int k, int lca, int a, int b){
    int aux = 0;
    if(lvl[a] - lvl[lca] + 1 >= k){
        aux = lvl[a] - k + 1;
        int lg = log2(lvl[a]);
        for(int i = lg; i >= 0; i--)
            if(lvl[padre[a][i]] >= aux)
                a = padre[a][i];
        return a;
    }
    k -= (lvl[a] - lvl[lca] + 1);
    aux = lvl[lca] + k;
    int lg = log2(lvl[b]);
    for(int i = lg; i >= 0; i--){
        if(lvl[padre[b][i]] >= aux)
            b = padre[b][i];
    }
    return b;
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
        for(int i = 1; i < n; i++){
            int n1, n2, w;
            cin>>n1>>n2>>w;
            adya[n1].push_back(mp(n2, w));
            adya[n2].push_back(mp(n1, w));
        }
        lvl[1] = 1;
        DFS(1, -1);
        for(int e = 1; e < loga; e++){
            for(int i = 1; i <= n; i++)
                padre[i][e] = padre[padre[i][e - 1]][e - 1];
        }
        string query;
        while(1){
            cin>>query;
            int a, b;
            if(query == "DONE") break;
            cin>>a>>b;
            int lca = LCA(a, b);
            if(query == "DIST")
                cout<<dist[a] + dist[b] - (2 * dist[lca])<<"\n";
            else{
                int k;
                cin>>k;
                cout<<find_kth(k, lca, a, b)<<"\n";
            }
        }
        for(int i = 1; i <= n; i++)
            adya[i].clear();
        cout<<"\n";
    }
    return 0;
}
