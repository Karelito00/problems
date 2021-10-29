#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[2500];
long long dist[2500];
int main()
{
    freopen("heatwv.in","r",stdin);
    freopen("heatwv.out","w",stdout);
    int n,t,ini,fin;
    cin>>n>>t>>ini>>fin;
    ini--;
    fin--;
    for(int u=0;u<t;u++){
        int nod1,nod2,peso;
        cin>>nod1>>nod2>>peso;
        nod1--;
        nod2--;
        nodos[nod1].push_back(make_pair(nod2,peso));
        nodos[nod2].push_back(make_pair(nod1,peso));
    }
    for(int y=0;y<n;y++)
        dist[y]=999999;
    priority_queue < pii, vector<pii>, greater <pii> > cola;
    cola.push(make_pair(0,ini));
    dist[ini]=0;
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        int nod=v.second,peso=v.first;
        if(peso<=dist[nod]){
            for(int i=0;i<nodos[nod].size();i++){
                int to=nodos[nod][i].first;
                int w=nodos[nod][i].second;
                if(w+dist[nod]<dist[to]){
                    dist[to]=w+dist[nod];
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    cout<<dist[fin];
    return 0;
}
