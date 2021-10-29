#include <bits/stdc++.h>

using namespace std;
vector <int> nodos[250];
int main()
{
    freopen("daisy.in","r",stdin);
    freopen("daisy.out","w",stdout);
    int a,t;
    cin>>a>>t;
    for(int i=0;i<t;i++){
        int nod,nod1;
        cin>>nod>>nod1;
        nod--;
        nod1--;
        nodos[nod].push_back(nod1);
        nodos[nod1].push_back(nod);
    }
    int c=0;
    queue <int> cola;
    for(int i=1;i<a;i++){
        cola.push(i);
        int dist[250];
        bool visited[250];
        memset(visited, false , sizeof (visited));
        memset(dist, 0 ,sizeof (dist));
        visited[i]=true;
        while(!cola.empty()){
            int v=cola.front();
            cola.pop();
            for(int k=0;k<nodos[v].size();k++){
                int to=nodos[v][k];
                if(visited[to]==false){
                    visited[to]=true;
                    cola.push(to);
                    dist[to]=dist[v]+1;
                }
            }
        }
        if(dist[0]==0){
            cout<<i+1<<endl;
            c=1;
        }
    }
    if(c==0)
        cout<<c;
    return 0;
}
