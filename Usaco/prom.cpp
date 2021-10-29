#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e4 + 2;

vector < int > adya[MAXn];
bool mark[MAXn];
int vdfs[MAXn];
int low[MAXn];
stack < int > pila;
int sol;
int cant;

void DFS(int v){
    pila.push(v);
    vdfs[v] = low[v] = ++cant;
    for(auto to: adya[v]){
        if(!vdfs[to]){
            DFS(to);
            low[v] = mn(low[v], low[to]);
        }
        else if(!mark[to])
            low[v] = mn(low[v], vdfs[to]);
    }
    if(vdfs[v] == low[v]){
        int aux = 0;
        while(!mark[v]){
            mark[pila.top()] = true;
            pila.pop();
            aux++;
        }
        if(aux >= 2)
            sol++;
    }
}

int main()
{
    freopen("prom.in","r",stdin);
    freopen("prom.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m ; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
    }
    for(int i = 1; i <= n; i++)
        if(!mark[i]) DFS(i);
    cout<<sol;
    return 0;
}
