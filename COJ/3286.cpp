#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector <int> adya[10001];

void bfs(int nodo){
    queue <int> cola;
    cola.push(nodo);
    visited[nodo]=true;
    while(!cola.empty()){
        int v=cola.front();
        cola.pop();
        for(int j=0;j<adya[v].size();j++){
            int to=adya[v][j];
            if(!visited[to]){
                visited[to]=true;
                cola.push(to);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n,m;
        cin>>n>>m;
        for(int j=0;j<m;j++){
            int n1,n2;
            cin>>n1>>n2;
            n1--,n2--;
            adya[n1].push_back(n2);
            adya[n2].push_back(n1);
        }
        long long con=0;
        for(int k=0;k<n;k++){
            if(!visited[k]){
                bfs(k);
                con++;
            }
        }
        long long suma=(con*(con+1))/2;
        cout<<suma-con<<"\n";
        memset(visited,0,sizeof visited);
        memset(adya,0,sizeof adya);
    }
    return 0;
}
