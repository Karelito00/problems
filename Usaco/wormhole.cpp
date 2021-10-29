#include <bits/stdc++.h>
#define MAX 999999
using namespace std;
class Edge{
public:
    int nodo,dest,peso;
    Edge(int nodo1,int dest1,int peso1){
    nodo=nodo1;
    dest=dest1;
    peso=peso1;
    }
};
vector <Edge> cam;
int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,m,h;
        cin>>n>>m>>h;
        vector <int> dist(n);
        for(int k=0;k<m;k++){
            int n1,n2,w;
            cin>>n1>>n2>>w;
            n1--,n2--;
            cam.push_back(Edge(n1,n2,w));
            cam.push_back(Edge(n2,n1,w));
        }
        for(int g=0;g<h;g++){
            int n1,n2,w;
            cin>>n1>>n2>>w;
            n1--,n2--;
            w*=-1;
            cam.push_back(Edge(n1,n2,w));
        }
        bool flag=false;
        fill(dist.begin(),dist.end(),0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m*2+h;j++){
                if(dist[cam[j].dest] > dist[cam[j].nodo] + cam[j].peso){
                    dist[cam[j].dest]=dist[cam[j].nodo] + cam[j].peso;
                }
            }
        }
        for(int k=0;k<m*2+h;k++){
            if(dist[cam[k].nodo]+cam[k].peso<dist[cam[k].dest]){
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        cam.clear();
    }
    return 0;
}
