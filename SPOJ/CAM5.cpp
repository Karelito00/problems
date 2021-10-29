#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e5 + 2;

vector < int > adya[MAXn];
bool visited[MAXn];

void DFS(int v){
    for(auto to: adya[v]){
        if(visited[to]) continue;
        visited[to] = true;
        DFS(to);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        for(int i = 1; i <= m; i++){
            int n1, n2;
            cin>>n1>>n2;
            adya[n1].push_back(n2);
            adya[n2].push_back(n1);
        }
        int sol = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                DFS(i);
                sol++;
            }
        }
        cout<<sol<<"\n";
        fill(visited, visited + n, false);
        for(int i = 0; i < n; i++)
            adya[i].clear();
    }
    return 0;
}
