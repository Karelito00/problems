#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

int cost[2001];
vector < pair <int,int> > adya[2001];
long long dist[2001];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&cost[i]);
    }
    for(int u=0;u<m;u++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        n1--,n2--;
        adya[n1].push_back(make_pair(n2,cost[n2]));
        adya[n2].push_back(make_pair(n1,cost[n1]));
    }
    priority_queue < pair <int,int> , vector < pair <int,int> > , greater < pair <int,int> > > cola;
    cola.push(make_pair(0,0));
    for(int i=1;i<n;i++)
        dist[i]=MAX;
    while(!cola.empty()){
        pair <int,int> v=cola.top();
        cola.pop();
        if(dist[v.second]>=v.first){
            for(int k=0;k<adya[v.second].size();k++){
                int to=adya[v.second][k].first;
                int dis=adya[v.second][k].second;
                if(dist[to]>dist[v.second]+dis){
                    dist[to]=dist[v.second]+dis;
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    printf("%lld",dist[n-1]-cost[n-1]);
    return 0;
}
