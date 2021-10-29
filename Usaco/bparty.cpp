#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[1000];
priority_queue < pii , vector <pii>, greater <pii> > cola;
int dist[1000];
int main()
{
    freopen("bparty.in","r",stdin);
    freopen("bparty.out","w",stdout);
    memset(dist, 999999 ,sizeof dist);
    int n,t,f;
    cin>>n>>t>>f;
    for(int i=0;i<t;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        nodos[a].push_back(make_pair(b,w));
        nodos[b].push_back(make_pair(a,w));
    }
    cola.push(make_pair(0,f-1));
    dist[f-1]=0;
    while(!cola.empty()){
        pii nod=cola.top();
        cola.pop();
        int v=nod.second,peso=nod.first;
        if(dist[v]>=peso){
            for(int i=0;i<nodos[v].size();i++){
                int j=nodos[v][i].first;
                int w=nodos[v][i].second;
                if(dist[v]+w <dist[j]){
                    dist[j]=dist[v]+w;
                    cola.push(make_pair(dist[j],j));
                }
            }
        }
    }
    int may=0;
    for(int y=0;y<n;y++){
       if(dist[y]*2>may)
            may=dist[y]*2;
    }
    cout<<may;
    return 0;
}
