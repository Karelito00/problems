#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e4 + 2;

vector < int > adya[MAXn];
int dist[MAXn];

void DFS(int v, int p){
    for(auto to: adya[v]){
        if(to == p) continue;
        dist[to] = dist[v] + 1;
        DFS(to, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    DFS(1, -1);
    int id = 1;
    for(int i = 2; i <= n; i++){
        if(dist[id] < dist[i])
            id = i;
    }
    fill(dist + 1, dist + n + 1, 0);
    DFS(id, -1);
    id = 1;
    for(int i = 2; i <= n; i++){
        if(dist[id] < dist[i])
            id = i;
    }
    cout<<dist[id];
    return 0;
}
