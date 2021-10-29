#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[1000];
int dist[1000];
int exi[1000];
int main()
{
    freopen("sparty.in","r",stdin);
    freopen("sparty.out","w",stdout);
    int a,t,fin;
    cin>>a>>t>>fin;
    fin--;
    for(int i=0;i<t;i++){
        int nod,ady,peso;
        cin>>nod>>ady>>peso;
        nod--;
        ady--;
        nodos[nod].push_back(make_pair(ady,peso));
    }
    for(int j=0;j<a;j++){
        dist[j]=999999;
        exi[j]=999999;
    }
    priority_queue < pii , vector <pii>, greater<pii> > fir;
    fir.push(make_pair(0,fin));
    dist[fin]=0;
    while(!fir.empty()){
        pii v=fir.top();
        fir.pop();
        int nod=v.second,peso=v.first;
        if(dist[nod]<=peso){
            for(int i=0;i<nodos[nod].size();i++){
                int n=nodos[nod][i].first,w=nodos[nod][i].second;
                if(dist[nod]+w<dist[n]){
                    dist[n]=dist[nod]+w;
                    fir.push(make_pair(dist[n],n));
                }
            }
        }
    }
    int mayor=0;
    for(int i=0;i<a;i++){
        if(i!=fin){
            priority_queue < pii, vector<pii>, greater<pii> > cola;
            cola.push(make_pair(0,i));
            exi[i]=0;
            while(!cola.empty()){
                pii v=cola.top();
                cola.pop();
                int nod=v.second,peso=v.first;
                if(exi[nod]>=peso){
                    for(int k=0;k<nodos[nod].size();k++){
                        int n=nodos[nod][k].first,w=nodos[nod][k].second;
                        if(exi[nod]+w<exi[n]){
                            exi[n]=exi[nod]+w;
                            cola.push(make_pair(exi[n],n));
                        }
                    }
                }
            }
            if(dist[i]+exi[fin]>mayor)
                mayor=dist[i]+exi[fin];
            for(int u=0;u<a;u++)
                exi[u]=999999;
        }
    }
    cout<<mayor;
    return 0;
}
