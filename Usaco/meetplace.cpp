#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 5, loga = log2(MAXn) + 2;

vector < int > adya[MAXn];
int lvl[MAXn];
int padre[MAXn][loga];
int maxlvl;
int n;

void dfs(int v){
    for(auto to: adya[v]){
        lvl[to] = lvl[v] + 1;
        dfs(to);
    }
    maxlvl = mx(maxlvl, lvl[v]);
}

void build_LCA(){
    for(int e = 1; (1 << e) < maxlvl; e++){
        for(int i = 2; i <= n; i++)
            padre[i][e] = padre[padre[i][e - 1]][e - 1];
    }
}

int LCA(int a, int b){
    if(lvl[a] < lvl[b])
        swap(a, b);
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

int main()
{
    freopen("meetplace.in","r",stdin);
    freopen("meetplace.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    lvl[1] = 1;
    for(int i = 2; i <= n; i++){
        int n1;
        cin>>n1;
        adya[n1].push_back(i);
        padre[i][0] = n1;
    }
    dfs(1);
    build_LCA();
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<LCA(a, b)<<"\n";
    }
    return 0;
}
