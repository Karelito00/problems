#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[50000];
int dist[50000];
int main()
{
    freopen("packdel.in","r",stdin);
    freopen("packdel.out","w",stdout);
    int a,m;
    cin>>a>>m;
    for(int i=0;i<m;i++){
        int n1,n2,peso;
        cin>>n1>>n2>>peso;
        n1--,n2--;
        nodos[n1].push_back(make_pair(n2,peso));
        nodos[n2].push_back(make_pair(n1,peso));
    }
    for(int k=1;k<a;k++)
        dist[k]=MAX;
    priority_queue <pii , vector <pii> , greater <pii> > cola;
    cola.push(make_pair(0,0));
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        int n=v.second,peso=v.first;
        if(dist[n]>=peso){
            for(int j=0;j<nodos[n].size();j++){
                int to=nodos[n][j].first;
                int w=nodos[n][j].second;
                if(dist[n]+w<dist[to]){
                    dist[to]=dist[n]+w;
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    cout<<dist[a-1];
    return 0;
}
