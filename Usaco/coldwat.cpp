#include <bits/stdc++.h>

using namespace std;

vector < int > nodos[99999];
int distancia[99999];
int main()
{
    freopen("coldwat.in","r",stdin);
    freopen("coldwat.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nodos[0].push_back(1);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        int tub,ady1,ady2;
        cin>>tub>>ady1>>ady2;
        nodos[tub].push_back(ady1);
        nodos[tub].push_back(ady2);
    }
    queue <int> cola;
    vector <bool> visited(a);
    cola.push(0);
    while(!cola.empty()){
        int v=cola.front();
        cola.pop();
        visited[v]=true;
        for(int o=0;o<nodos[v].size();o++){
            int to=nodos[v][o];
            if(visited[to]==false){
                visited[to]=true;
                cola.push(to);
                distancia[to]=distancia[v]+1;
            }
        }
    }
    for(int i=1;i<=a;i++)
    cout<<distancia[i]<<"\n";

    return 0;
}
