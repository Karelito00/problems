#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define mx(a, b) (a > b ? a : b)
#define mn(a, b) (a < b ? a : b)

using namespace std;

int const MAXn = 1e5 + 2, loga = log2(MAXn) + 2;

vector < pair < int , int > > adya[MAXn];
int lvl[MAXn];
int padre[MAXn][loga];
int maxm[MAXn][loga];
int minm[MAXn][loga];
int n;

void DFS(int v, int p){
    for(auto to: adya[v]){
        if(to.f == p) continue;
        maxm[to.f][0] = to.s;
        minm[to.f][0] = to.s;
        padre[to.f][0] = v;
        lvl[to.f] = lvl[v] + 1;
        DFS(to.f, v);
    }
}

void prepar(){
    for(int e = 1; (1<<e) < n; e++){
        for(int i = 1; i <= n; i++){
            padre[i][e] = padre[padre[i][e - 1]][e - 1];
            if(padre[i][e] != 0){
                minm[i][e] = mn(minm[i][e - 1], minm[padre[i][e - 1]][e - 1]);
                maxm[i][e] = mx(maxm[i][e - 1], maxm[padre[i][e - 1]][e - 1]);
            }
        }
    }
}

pair < int , int > LCA(int a, int b){
    int mi = INT_MAX, ma = 0;
    if(lvl[a] < lvl[b]) swap(a, b);
    int lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--){
        if(lvl[padre[a][i]] >= lvl[b]){
            mi = mn(mi, minm[a][i]);
            ma = mx(ma, maxm[a][i]);
            a = padre[a][i];
        }
    }
    if(a == b) return mp(mi, ma);
    lg = log2(lvl[a]);
    for(int i = lg; i >= 0; i--){
        if(padre[a][i] != padre[b][i]){
            mi = mn(mi, mn(minm[a][i], minm[b][i]));
            ma = mx(ma, mx(maxm[a][i], maxm[b][i]));
            a = padre[a][i];
            b = padre[b][i];
        }
    }
    mi = mn(mi, minm[b][0]);
    ma = mx(ma, maxm[b][0]);
    return mp(mn(minm[a][0], mi), mx(ma, maxm[a][0]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i < n; i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        adya[n1].push_back(mp(n2, w));
        adya[n2].push_back(mp(n1, w));
    }
    lvl[1] = 1;
    DFS(1, -1);
    prepar();
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        pair < int , int > sol = LCA(a, b);
        cout<<sol.f<<" "<<sol.s<<"\n";
     }
    return 0;
}
