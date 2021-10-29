#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int const MAXn = 1e5 + 5,
            lg = log2(MAXn) + 2;
int n,m;
struct arist{
    int nod1, nod2, cost;
    bool operator < (const arist &var)const{
        return var.cost < cost;
    }
}arr[400001];

vector < pair < int , int > > adya[MAXn];
int p[MAXn];
int lvl[MAXn], padre[MAXn][lg], cost[MAXn][lg];

int find_set(int x){
    if(x == p[x])
        return x;
    return p[x] = find_set(p[x]);
}

void BFS(){
    queue < int > cola;
    cola.push(1);
    lvl[1] = 1;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int j=0;j<(int)adya[v].size();j++){
            int to = adya[v][j].first;
            int peso = adya[v][j].second;
            if(!lvl[to]){
                lvl[to] = lvl[v] + 1;
                padre[to][0] = v;
                cost[to][0] = peso;
                cola.push(to);
            }
        }
    }
    for(int e=1;(1<<e)<n;e++){
        for(int i=1;i<=n;i++){
            padre[i][e] = padre[padre[i][e-1]][e-1];
            if(cost[i][e-1] == 0  || cost[padre[i][e-1]][e-1] == 0)
                continue;
            cost[i][e] = mn(cost[i][e-1],cost[padre[i][e-1]][e-1]);
        }
    }
}

int LCA(int a,int b){
    int sol = 1000000000;
    if(lvl[b] > lvl[a])
        swap(a,b);
    int loga = log2(n+1);
    for(int i=loga;i>=0;i--){
        if(lvl[padre[a][i]] >= lvl[b]){
            sol = mn(sol,cost[a][i]);
            a = padre[a][i];
        }
    }
    if(a == b)
        return sol;
    for(int i=loga;i>=0;i--){
        if(padre[a][i] != 0 && padre[a][i] != padre[b][i]){
            sol = mn(sol , mn(cost[a][i],cost[b][i]));
            a = padre[a][i], b = padre[b][i];
        }
    }
    return mn(sol,mn(cost[a][0],cost[b][0]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i].nod1>>arr[i].nod2>>arr[i].cost;
    }
    for(int i=1;i<=n;i++)
        p[i] = i;
    sort(arr,arr+m);
    for(int i=0;i<m;i++){
        int n1 = arr[i].nod1;
        int n2 = arr[i].nod2;
        int set1 = find_set(n1);
        int set2 = find_set(n2);
        if(set1 != set2){
            p[set2] = set1;
            adya[n1].push_back(make_pair(n2,arr[i].cost));
            adya[n2].push_back(make_pair(n1,arr[i].cost));
        }
    }
    BFS();
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b) - 1<<"\n";
    }
    return 0;
}
