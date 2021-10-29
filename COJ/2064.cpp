#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

int dist[30001];
int arr[30001];
vector < pair <int,int> > adya[30001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    while(a--){
        int n;
        cin>>n;
        for(int h=0;h<n-1;h++){
            int n1,n2,p;
            cin>>n1>>n2>>p;
            n1--,n2--;
            adya[n1].push_back(make_pair(n2,p));
            adya[n2].push_back(make_pair(n1,p));
        }
        for(int k=0;k<n;k++)
            dist[k]=MAX;
        dist[0]=0;
        queue < int > cola;
        cola.push(0);
        pair <int,int> fin;
        while(!cola.empty()){
            int v=cola.front();
            cola.pop();
            for(int y=0;y<(int)adya[v].size();y++){
                int to=adya[v][y].first;
                int w=adya[v][y].second;
                if(dist[to]>dist[v]+w){
                    dist[to]=dist[v]+w;
                    if(dist[to]>fin.second){
                        fin.second=dist[to];
                        fin.first=to;
                    }
                    cola.push(to);
                }
            }
        }
        for(int k=0;k<n;k++)
            dist[k]=MAX;
        dist[fin.first]=0;
        cola.push(fin.first);
        pair <int,int> best;
        arr[fin.first]=fin.first;
        while(!cola.empty()){
            int v=cola.front();
            cola.pop();
            for(int y=0;y<(int)adya[v].size();y++){
                int to=adya[v][y].first;
                int w=adya[v][y].second;
                if(dist[to]>dist[v]+w){
                    dist[to]=dist[v]+w;
                    if(dist[to]>best.second){
                        best.second=dist[to];
                        best.first=to;
                    }
                    cola.push(to);
                    arr[to]=v;
                }
            }
        }
        int x=best.first;
        float h=((float)(best.second))/2;
        pair < float, pair <int,int> > sol;
        sol.first=MAX;
        while(arr[x]!=x){
            if(abs(dist[x]-h)<sol.first){
                sol.first=abs(dist[x]-h);
                sol.second.first=x;
                sol.second.second=dist[x];
            }
            else if(abs(dist[x]-h)==sol.first && sol.second.first>x){
                sol.first=abs(dist[x]-h);
                sol.second.first=x;
                sol.second.second=dist[x];
            }
            x=arr[x];
        }
        sol.second.second=max(sol.second.second,dist[best.first]-sol.second.second);
        cout<<sol.second.first+1<<" "<<sol.second.second<<"\n";
        memset(adya,0,sizeof adya);
    }
    return 0;
}
