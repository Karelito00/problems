#include <bits/stdc++.h>

using namespace std;
int z[101];
vector <int> adya[1001];
bool visited[1001];
int dist[1001];
int main()
{
    freopen("picnic.in","r",stdin);
    freopen("picnic.out","w",stdout);
    int a,n,m;
    cin>>a>>n>>m;
    for(int y=0;y<a;y++){
        cin>>z[y];
        z[y]--;
    }
    for(int h=0;h<m;h++){
        int n1,n2;
        cin>>n1>>n2;
        n1--,n2--;
        adya[n1].push_back(n2);
    }
    int cant=0;
    stack <int> pila;
    for(int i=0;i<a;i++){
        pila.push(z[i]);
        dist[z[i]]++;;
        visited[z[i]]=true;
        while(!pila.empty()){
            int v=pila.top();
            pila.pop();
            for(int y=0;y<adya[v].size();y++){
                int to=adya[v][y];
                if(!visited[to]){
                    visited[to]=true;
                    pila.push(to);
                    dist[to]++;
                }
            }
        }
        memset(visited,0,sizeof visited);
    }
    for(int h=0;h<n;h++)
        if(dist[h]==a)
            cant++;
    cout<<cant;
    return 0;
}
