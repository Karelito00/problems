#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

typedef pair < int,int > pii;
int dist[501];
vector <pii> adya[501];

int main()
{
    int a,m,c,t;
    scanf("%d %d %d %d",&a,&m,&c,&t);
    for(int u=0;u<m;u++){
        int n1,n2,p;
        scanf("%d %d %d",&n1,&n2,&p);
        n1--,n2--;
        adya[n1].push_back(make_pair(n2,p));
        adya[n2].push_back(make_pair(n1,p));
    }
    priority_queue <pii , vector <pii> , greater <pii> > cola;
    cola.push(make_pair(0,0));
    for(int d=1;d<a;d++)
        dist[d]=MAX;
    while(!cola.empty()){
        int v=cola.top().second,p=cola.top().first;
        cola.pop();
        if(dist[v]>=p){
            for(int k=0;k<adya[v].size();k++){
                int to=adya[v][k].first,w=adya[v][k].second;
                if(dist[to]>dist[v]+w){
                    dist[to]=dist[v]+w;
                    cola.push(make_pair(dist[to],to));
                }
            }
        }
    }
    vector <int> cow;
    for(int h=0;h<c;h++){
        int co;
        scanf("%d",&co);
        co--;
        if(dist[co]<=t)
            cow.push_back(h+1);
    }
    printf("%d\n",(int)cow.size());
    for(int y=0;y<cow.size();y++)
        printf("%d\n",cow[y]);
    return 0;
}
