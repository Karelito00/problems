#include <bits/stdc++.h>

using namespace std;

const int MAXn = 100001;
int n,m;
long long k;
vector < int > adya[MAXn];
int comp;
bool visited[MAXn];
queue < int > cola;

struct karel{
    long long sin;
    bool operator < (const karel &hola)const{
        return hola.sin < sin;
    }
};
struct Element{
    long long nodos;
    bool operator < (const Element &hola)const{
        return hola.nodos < nodos;
    }
};

karel cam[MAXn];
Element z[MAXn];

void BFS(int nod){
    cola.push(nod);
    long long con = 0;
    long long nodos2 = 1;
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        for(int i=0;i<(int)adya[v].size();i++){
            int to = adya[v][i];
            con++;
            if(!visited[to]){
                nodos2++;
                visited[to] = true;
                cola.push(to);
            }
        }
    }
    con/=2;
    cam[comp].sin = ((nodos2 * (nodos2 - 1)) / 2) - con;
    z[comp].nodos = nodos2;
}

int main()
{
    freopen("unob.in","r",stdin);
    freopen("unob.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            comp++;
            visited[i] = true;
            BFS(i);
        }
    }
    long long cantmin = comp - k;
    if(cantmin <= 0) cantmin = 1;
    long long cantmax = comp;
    sort(cam+1,cam+1+comp);
    for(int i=1;i<=comp;i++){
        if(cantmax <= 1)
            break;
        k -= cam[i].sin;
        if(k <= 0){
            cout<<cantmin<<" "<<cantmax;
            return 0;
        }
    }
    sort(z+1,z+n+1);
    long long no = z[1].nodos;
    for(int i=2;i<=comp;i++){
        cantmax --;
        k -= no * z[i].nodos;
        no += z[i].nodos;
        if(k <= 0)
            break;
        if(cantmax <= 1)
            break;
    }
    if(cantmax < 1)
        cantmax = 1;
    cout<<cantmin<<" "<<cantmax;
    return 0;
}
