#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int n, m;
long long r, e;
bool visited[1001];
vector < int > adya[1001];
queue < int > cola;
int cantcomp;

struct par{
    long long rutas;
    long long nodos;
}comp[1001];

void BFS(int nod){
    cola.push(nod);
    int cantnodos = 1;
    int caminos = 0;
    visited[nod] = true;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(auto to: adya[v]){
            if(!visited[to]){
                visited[to] = true;
                cantnodos++;
                cola.push(to);
            }
            caminos++;
        }
    }
    caminos /= 2;
    comp[cantcomp].nodos = cantnodos;
    comp[cantcomp].rutas = ((cantnodos * (cantnodos - 1)) / 2) - caminos;
    cantcomp++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>r>>e;
    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        n1--, n2--;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }

    for(int i=0;i<n;i++)
        if(!visited[i])
            BFS(i);
    int sol = 0;
    for(int i=0;i<cantcomp;i++){
        sol += mn(comp[i].nodos * e, comp[i].rutas * r);
    }
    cout<<sol;
    return 0;
}
