#include <bits/stdc++.h>
#define MAX 99999999
#define NODOS n*m

using namespace std;

vector < pair <int,int> > adya[10001];
int n,m;
int mat[101][101];
int pos[]={1,-1,0,0};
int dist[10001];
priority_queue < pair <int,int> , vector < pair <int,int> > , greater < pair <int,int> > > cola;

int new_nodo(int y,int x){
    return (y*m)+x+1;
}

void adyacentes(int y,int x){
    int nodo=new_nodo(y,x);
    for(int h=0;h<4;h++){
        int cy=pos[h],cx=pos[3-h];
        if(y+cy>=0 && y+cy<n && x+cx>=0 && x+cx<m){
            adya[nodo].push_back(make_pair(new_nodo(y+cy,x+cx),mat[y+cy][x+cx]));
        }
    }
}
void dijkstra(int nod){
    for(int u=1;u<=NODOS;u++){
        dist[u]=MAX;
    }
    int peso=mat[(nod-1)/m][(nod-1)%m];
    dist[nod]=peso;
    cola.push(make_pair(peso,nod));
    while(!cola.empty()){
        int v=cola.top().second;
        long long p=cola.top().first;
        cola.pop();
        if(dist[v]>=p){
            for(int y=0;y<(int)adya[v].size();y++){
                int to=adya[v][y].first,w=adya[v][y].second;
                if(dist[to]>dist[v]+w){
                    dist[to]=dist[v]+w;
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            adyacentes(i,j);
        }
    }
    int best=MAX;
    for(int u=1;u<=NODOS-m+1;u+=m){
        dijkstra(u);
        for(int h=m;h<=NODOS;h+=m){
            if(best>dist[h]){
                best=dist[h];
            }
        }
    }
    cout<<best;
    return 0;
}
