#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int n,m,q;
int const MAXn = 3001,
            lg = log2(3001);

typedef pair < int , int > par;
typedef pair < int , pair < int , int > > trio;

int p[MAXn];
vector < trio > arist;
vector < par > adya[MAXn];
int cost[MAXn][lg+2];
int padre[MAXn][lg+2];
int lvl[3001];


void BFS(){
    queue < int > cola;
    cola.push(1);
    lvl[1] = 1;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int i=0;i<(int)adya[v].size();i++){
            int to = adya[v][i].first, w = adya[v][i].second;
            if(lvl[to] == 0){
                cola.push(to);
                lvl[to] = lvl[v] + 1;
                padre[to][0] = v;
                cost[to][0] = w;
            }
        }
    }
}

void prepar(){
    for(int i=1;(1<<i)<=n;i++){
        for(int j=2;j<=n;j++){
            padre[j][i] = padre[ padre[j][i-1] ][i-1];
            if(cost[padre[j][i-1]][i-1])
                cost[j][i] = mx(cost[ padre[j][i-1] ][i-1], cost[j][i-1]);
        }
    }
}

int LCA(int a,int b){
    int maxm = 0;
    if(lvl[a] < lvl[b])
        swap(a,b);
    int lt = log2(n);
    for(int i=lt;i>=0;i--)
        if(lvl[padre[a][i]] >= lvl[b])
            maxm = mx(maxm,cost[a][i]), a = padre[a][i];
    if(a == b)
        return maxm;
    for(int i=lt;i>=0;i--){
        if(padre[a][i] != 0 && padre[a][i] != padre[b][i])
            maxm = mx(maxm,mx(cost[a][i],cost[b][i])),a = padre[a][i], b = padre[b][i];
    }
    return mx(maxm,mx(cost[a][0],cost[b][0]));
}

int find_set(int x){
    if(x == p[x])
        return x;
    return p[x] = find_set(p[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int n1,n2,peso;
        cin>>n1>>n2>>peso;
        arist.push_back(make_pair(peso,make_pair(n1,n2)));
    }

    for(int h=1;h<=n;h++)
        p[h] = h;

    sort(arist.begin(),arist.end());

    for(int j=0;j<m;j++){
        int n1 = arist[j].second.first;
        int n2 = arist[j].second.second;
        int peso = arist[j].first;
        int set1 = find_set(n1);
        int set2 = find_set(n2);
        if(set1 != set2){
            p[set1] = set2;
            adya[n1].push_back(make_pair(n2,peso));
            adya[n2].push_back(make_pair(n1,peso));
        }
    }
    BFS();
    prepar();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<"\n";
    }

    return 0;
}
