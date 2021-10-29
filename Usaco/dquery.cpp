#include <bits/stdc++.h>

using namespace std;

int const MAXn = 40001,
          loga = log2(MAXn);
typedef pair < int , int > par;

vector < par > adya[MAXn];
int dist[MAXn];
int n,m,q;
int lvl[MAXn];
int padre[MAXn][loga+3];

void BFS(){
    queue < int > cola;
    cola.push(1);
    lvl[1] = 1;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int i=0;i<(int)adya[v].size();i++){
            int to = adya[v][i].first, w = adya[v][i].second;
            if(!lvl[to]){
                dist[to] = dist[v] + w;
                lvl[to] = lvl[v] + 1;
                padre[to][0] = v;
                cola.push(to);
            }
        }
    }
}

void prepar(){
    int lg = log2(n);
    for(int i=1;i<=lg;i++){
        for(int j=2;j<=n;j++){
            padre[j][i] = padre[ padre[j][i-1] ][i-1];
        }
    }
}

int LCA(int a,int b){
    if(lvl[a] < lvl[b])
        swap(a,b);
    int lg = log2(n);
    for(int i=lg;i>=0;i--)
        if(lvl[ padre[a][i] ] >= lvl[b])
            a = padre[a][i];
    if(a == b)
        return a;
    for(int i=lg;i>=0;i--)
        if(padre[a][i] != padre[b][i])
            a = padre[a][i], b = padre[b][i];
    return padre[a][0];
}

int main()
{
    freopen("dquery.in","r",stdin);
    freopen("dquery.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int n1,n2,p;
        char x;
        cin>>n1>>n2>>p>>x;
        adya[n1].push_back(make_pair(n2,p));
        adya[n2].push_back(make_pair(n1,p));
    }

    BFS();
    prepar();

    cin>>q;
    for(int i=0;i<q;i++){
        int n1,n2;
        cin>>n1>>n2;
        int nod = LCA(n1,n2);
        cout<<dist[n1] + dist[n2] - (2 * dist[nod])<<"\n";
    }
    return 0;
}
