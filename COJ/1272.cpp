#include <bits/stdc++.h>

using namespace std;

bool visited[20001];
pair <int,int> dist[20001];
int cant[20001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int k=0;k<a;k++){
        vector <int> adya[20001];
        int n,m;
        cin>>n>>m;
        for(int k=0;k<m;k++){
            int n1,n2;
            cin>>n1>>n2;
            n1--,n2--;
            adya[n1].push_back(n2);
            adya[n2].push_back(n1);
        }
        queue <int> cola;
        cola.push(0);
        visited[0]=true;
        dist[0].second=0;
        while(!cola.empty()){
            int v=cola.front();
            cola.pop();
            for(int k=0;k<adya[v].size();k++){
                int to=adya[v][k];
                if(visited[to]==false){
                    visited[to]=true;
                    cola.push(to);
                    dist[to].first=dist[v].first+1;
                    dist[to].second=dist[v].second+1;
                    cant[dist[to].second]++;
                }
            }
        }
        pair <int, int > best;
        best.first=0;
        for(int k=0;k<n;k++){
            if(dist[k].first>best.first){
                best.first=dist[k].first;
                best.second=k+1;
            }
        }
        cout<<best.second<<" "<<dist[best.second-1].second<<" "<<cant[dist[best.second-1].second]<<"\n";
        memset(visited,0,sizeof visited);
        memset(cant,0,sizeof cant);
        memset(dist,0,sizeof dist);
    }
    return 0;
}
