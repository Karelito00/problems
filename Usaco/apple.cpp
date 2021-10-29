#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[100000];
long long dist[100000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int t,a,ini,d1,d2;
    cin>>t>>a>>ini>>d1>>d2;
    ini--,d1--,d2--;
    for(int u=0;u<t;u++){
        int nod1,nod2,peso;
        cin>>nod1>>nod2>>peso;
        nod1--;
        nod2--;
        nodos[nod1].push_back(make_pair(nod2,peso));
        nodos[nod2].push_back(make_pair(nod1,peso));
    }
    for(int o=0;o<a;o++)
        dist[o]=9999999;
    priority_queue <pii , vector <pii> , greater <pii> > cola;
    cola.push(make_pair(0,ini));
    dist[ini]=0;
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        int n=v.second,peso=v.first;
        if(dist[n]<=peso){
            for(int y=0;y<nodos[n].size();y++){
                int to=nodos[n][y].first,w=nodos[n][y].second;
                if(w+dist[n]<dist[to]){
                    dist[to]=w+dist[n];
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    long long suma=0,com=0,fin=0;
    if(dist[d1]<dist[d2]){
        suma=dist[d1];
        com=d1;
        fin=d2;
    }
    else{
        suma=dist[d2];
        com=d2;
        fin=d1;
    }
    for(int i=0;i<a;i++)
        dist[i]=9999999;
        dist[com]=0;
    cola.push(make_pair(0,com));
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        long long n=v.second,peso=v.first;
        if(dist[n]<=peso){
            for(int y=0;y<nodos[n].size();y++){
                int to=nodos[n][y].first,w=nodos[n][y].second;
                if(w+dist[n]<dist[to]){
                    dist[to]=w+dist[n];
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    cout<<suma+dist[fin];
    return 0;
}
