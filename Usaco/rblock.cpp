#include <bits/stdc++.h>
#define MAX 9999999
using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[100];
int dist[100];
vector <int> cam[100];
int main()
{
    freopen("rblock.in","r",stdin);
    freopen("rblock.out","w",stdout);
    int a,t;
    cin>>a>>t;
    for(int i=0;i<t;i++){
        int ad1,ad2,peso;
        cin>>ad1>>ad2>>peso;
        ad1--,ad2--;
        nodos[ad1].push_back(make_pair(ad2,peso));
        nodos[ad2].push_back(make_pair(ad1,peso));
    }
    for(int j=0;j<a;j++){
        dist[j]=MAX;
    }
    priority_queue < pii , vector <pii> , greater <pii> > cola;
    cola.push(make_pair(0,0));
    dist[0]=0;
    cam[0].push_back(0);
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        int nod=v.second,peso=v.first;
        if(dist[nod] <= peso){
            for(int k=0;k<nodos[nod].size();k++){
                int to=nodos[nod][k].first,w=nodos[nod][k].second;
                if(dist[nod] + w < dist[to]){
                    dist[to]=dist[nod]+w;
                    cam[to]=cam[nod];
                    cam[to].push_back(to);
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    int minimo=dist[a-1],maxm=0;
    for(int u=0;u<cam[a-1].size()-1;u++){
        int n1=cam[a-1][u],n2=cam[a-1][u+1],in1=0,in2=0;
        for(int i=0;i<nodos[n1].size();i++){
            if(nodos[n1][i].first==n2){
                nodos[n1][i].second*=2;
                in1=i;
                break;
            }
        }
        for(int i=0;i<nodos[n2].size();i++){
            if(nodos[n2][i].first==n1){
                nodos[n2][i].second*=2;
                in2=i;
                break;
            }
        }
        for(int j=0;j<a;j++)
            dist[j]=MAX;
        cola.push(make_pair(0,0));
        dist[0]=0;
        while(!cola.empty()){
            pii v=cola.top();
            cola.pop();
            int nod=v.second,peso=v.first;
            if(dist[nod] <= peso){
                for(int k=0;k<nodos[nod].size();k++){
                    int to=nodos[nod][k].first,w=nodos[nod][k].second;
                    if(dist[nod] + w < dist[to]){
                        dist[to]=dist[nod]+w;
                        cola.push(make_pair(dist[to],to));
                    }
                }
            }
        }
        if(dist[a-1]>maxm)
            maxm=dist[a-1];
        nodos[n1][in1].second/=2;
        nodos[n2][in2].second/=2;
    }
    cout<<maxm-minimo;
    return 0;
}
