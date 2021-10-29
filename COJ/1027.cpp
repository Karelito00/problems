#include <bits/stdc++.h>
#define MAX 999999

using namespace std;

class Elements{
public:
    int out;
    float tempa;
    float dista;
    Elements(int out1,float tempa1,float dista1){
        out=out1;
        tempa=tempa1;
        dista=dista1;
    }
    Elements(){}
    bool operator < (const Elements& hola)const{
        if(hola.tempa!=tempa)
            return hola.tempa<tempa;
        return hola.dista<dista;
    }
};
float dist[101];
vector <Elements> adya[101];
int main()
{
    int n,m;
    while(cin>>n>>m){
    int ini,fin;
    cin>>ini>>fin;
    vector <float> temperaturas;
    for(int h=0;h<m;h++){
        int n1,n2;
        float dis,temp;
        cin>>n1>>n2>>temp>>dis;
        n1--,n2--;
        adya[n1].push_back(Elements(n2,temp,dis));
        adya[n2].push_back(Elements(n1,temp,dis));
        temperaturas.push_back(temp);
    }
    sort(temperaturas.begin(),temperaturas.end());
    for(int u=0;u<temperaturas.size();u++){
        priority_queue < pair < float ,int > , vector < pair <float,int > > , greater < pair < float , int > > > cola;
        float hay=temperaturas[u];
        bool flag=false;
        vector <int> cam[101];
        for(int h=0;h<n;h++){
            dist[h]=MAX;
        }
        dist[ini-1]=0;
        cam[ini-1].push_back(ini);
        cola.push(make_pair(0,ini-1));
        while(!cola.empty()){
            pair <int,int> v=cola.top();
            cola.pop();
            if(dist[v.second]>=v.first){
                for(int y=0;y<adya[v.second].size();y++){
                    int to=adya[v.second][y].out;
                    float tem=adya[v.second][y].tempa;
                    float dis=adya[v.second][y].dista;
                    if(dist[to]>dist[v.second]+dis && tem<=hay){
                        dist[to]=dist[v.second]+dis;
                        cam[to]=cam[v.second];
                        cam[to].push_back(to+1);
                        cola.push(make_pair(dist[to],to));
                        if(to==fin-1)
                            flag=true;
                    }
                }
            }
        }
        if(flag){
            for(int y=0;y<cam[fin-1].size();y++){
                cout<<cam[fin-1][y]<<" ";
            }
            cout<<"\n";
            printf("%.1f %.1f\n",dist[fin-1],hay);
            break;
        }
    }
    memset(adya,0,sizeof adya);
    }
    return 0;
}
