#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair < int , int > par;

map < string , int > mapa;
vector < int > adya[303];
int dist[303];
queue < int > cola;
set < string > resp;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int id = 0;
    string aux = "Isenbaev";
    mapa[aux] = ++id;
    for(int i = 1; i <= n; i++){
        string a, b, c;
        cin>>a>>b>>c;
        resp.insert(a);
        resp.insert(b);
        resp.insert(c);
        if(mapa.find(a) == mapa.end()) mapa[a] = ++id;
        if(mapa.find(b) == mapa.end()) mapa[b] = ++id;
        if(mapa.find(c) == mapa.end()) mapa[c] = ++id;
        adya[mapa[a]].push_back(mapa[b]);
        adya[mapa[a]].push_back(mapa[c]);
        adya[mapa[b]].push_back(mapa[a]);
        adya[mapa[b]].push_back(mapa[c]);
        adya[mapa[c]].push_back(mapa[a]);
        adya[mapa[c]].push_back(mapa[b]);
    }
    fill(dist + 1, dist + id + 1, INT_MAX);
    dist[1] = 0;
    cola.push(1);
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(auto to: adya[v]){
            if(dist[v] + 1 < dist[to]){
                dist[to] = dist[v] + 1;
                cola.push(to);
            }
        }
    }
    for(auto x: resp){
        cout<<x<<" ";
        if(dist[mapa[x]] == INT_MAX)
            cout<<"undefined";
        else
            cout<<dist[mapa[x]];
        cout<<"\n";
    }
    return 0;
}
