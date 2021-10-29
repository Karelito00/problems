#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e4 + 4;

vector < int > adya[MAXn];
bool visited[MAXn];

void DFS(int v, int p){
    for(auto to: adya[v]){
        if(to == p) continue;
        if(visited[to]){
            cout<<"NO";
            exit(0);
        }
        visited[to] = true;
        DFS(to, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    visited[1] = true;
    DFS(1, -1);
    for(int i = 1; i <= n; i++)
        if(!visited[i]){
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}
