#include <bits/stdc++.h>

using namespace std;

vector < int > adya[102];
int dist[102];

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] == s[j]){
                adya[i + 1].push_back(j + 1);
                adya[j + 1].push_back(i + 1);
            }
        }
        if(i > 0 && s[i] != s[i - 1]) adya[i + 1].push_back(i);
        if(i < n - 1 && s[i] != s[i + 1]) adya[i + 1].push_back(i + 2);
    }
    queue < int > cola;
    fill(dist + 1, dist + n + 1, 100000);
    dist[1] = 0;
    cola.push(1);
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(auto to: adya[v]){
            if(dist[to] > dist[v] + 1){
                cola.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    cout<<dist[n];
    return 0;
}
