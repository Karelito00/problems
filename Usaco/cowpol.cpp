#include <bits/stdc++.h>
#define MAX 200001
#define mx(x,y) (x > y ? x : y)

using namespace std;

vector <int> adya[MAX];
vector <int> pol[MAX/2];
int n,k;
int lvl[MAX],p[MAX][18];

void build_LCA(int nod){
    queue <int> cola;
    cola.push(nod);
    lvl[nod] = 1;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int i=0;i<(int)adya[v].size();i++){
            int to = adya[v][i];
            if(lvl[to])
                continue;
            cola.push(to);
            lvl[to] = lvl[v] + 1;
            p[to][0] = v;
        }
    }
}

void prep(){
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j<=n;j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}

int LCA(int y,int x){
    if(lvl[x]<lvl[y])
        swap(x,y);
    int lg = log2(lvl[x]);
    for(int i=lg;i>=0;i--)
        if(lvl[x]-(1<<i)>=lvl[y])
            x = p[x][i];
    if(x==y)
        return x;
    for(int i=lg;i>=0;i--)
        if(p[x][i]!=0 && p[x][i]!=p[y][i])
            x = p[x][i], y = p[y][i];
    return p[x][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int padre=0;;
    for(int i=1;i<=n;i++){
        int po,pad;
        cin>>po>>pad;
        if(pad!=0){
            adya[pad].push_back(i);
            adya[i].push_back(pad);
        }
        else padre = i;
        pol[po].push_back(i);
    }

    build_LCA(padre);
    prep();

    for(int i=1;i<=k;i++){
        int best = 0;
        int nod=0;
        int me=0;
        int tam = pol[i].size();
        for(int l=0;l<tam;l++){
            int n1 = pol[i][l];
            if(me<lvl[n1]){
                me = lvl[n1];
                nod = n1;
            }
        }
        for(int j=0;j<tam;j++){
            int n2 = pol[i][j];
            if(nod==n2)
                continue;
            int o=LCA(nod,n2);
            best = mx(best,((lvl[nod]-1)+(lvl[n2]-1))-(2*(lvl[o]-1)));
        }
        cout<<best<<"\n";
    }
    return 0;
}
