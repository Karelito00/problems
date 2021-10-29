#include <bits/stdc++.h>

using namespace std;
vector <int> adya[101];
pair <int,int> dist[100];
bool visited[101];
int main()
{
    int a,ini;
    cin>>a>>ini;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            int n;
            cin>>n;
            if(n){
                adya[i].push_back(j);
            }
        }
    }
    for(int k=0;k<a;k++)
        dist[k].second=k+1;
    queue <int> cola;
    cola.push(ini-1);
    visited[ini-1]=true;
    dist[ini-1].first=1;
    while(!cola.empty()){
        int k=cola.front();
        cola.pop();
        for(int l=0;l<adya[k].size();l++){
            if(!visited[adya[k][l]]){
                dist[adya[k][l]].first=dist[k].first+1;
                cola.push(adya[k][l]);
                visited[adya[k][l]]=true;
            }
        }
    }
    sort(dist,dist+a);
    int c=1;
    for(int o=0;o<a;o++){
        if(dist[o].first==c)
            cout<<dist[o].second<<" ";
        else if(dist[o].first!=0)
        {
            cout<<endl;
            cout<<dist[o].second<<" ";
            c++;
        }
    }
    return 0;
}
