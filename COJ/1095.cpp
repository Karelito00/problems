#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

vector < int > adya[MAXn];
vector < int > adya2[MAXn];
bool mark[MAXn];
int vlowlink[MAXn];
int vdfs[MAXn];
int top_sort[MAXn];
int cont;
vector < int > comp;
stack < int > pila;

void dfs(int v){
    vlowlink[v] = vdfs[v] = ++cont;
    pila.push(v);
    for(auto to: adya2[v]){
        if(!vdfs[to]){
            dfs(to);
            vlowlink[v] = mn(vlowlink[v], vlowlink[to]);
        }
        else if(!mark[to])
            vlowlink[v] = mn(vdfs[to], vlowlink[v]);
    }
    if(vdfs[v] == vlowlink[v]){
        while(!mark[v]){
            mark[pila.top()] = true;
            pila.pop();
        }
        comp.push_back(v);
    }
}

void dfs1(int v){
    for(auto to: adya[v]){
        if(!mark[to]){
            mark[to] = true;
            dfs1(to);
        }
    }
    top_sort[++cont] = v;
}

int main()
{
    //freopen("1.in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for(int i = 0; i < m; i++){
            int n1, n2;
            cin>>n1>>n2;
            adya[n1].push_back(n2);
            adya2[n2].push_back(n1);
        }
        for(int i = 1; i <= n; i++){
            if(!mark[i]){
                mark[i] = true;
                dfs1(i);
            }
        }
        fill(mark + 1, mark + n + 1, false);
        cont = 0;
        for(int i = n; i >= 1; i--){
            if(!mark[top_sort[i]])
                dfs(top_sort[i]);
        }
        fill(mark + 1, mark + n + 1, 0);
        for(int i = 1; i <= n; i++){
            for(auto to: adya2[i])
                if(vlowlink[to] != vlowlink[i]) mark[vlowlink[i]] = true;
        }
        int sol = 0;
        for(auto x: comp)
            if(!mark[vlowlink[x]]) sol++;
        comp.clear();
        fill(mark + 1, mark + n + 1, 0);
        fill(vdfs + 1, vdfs + n + 1, 0);
        fill(vlowlink + 1, vlowlink + n + 1, 0);
        cout<<sol<<"\n";
        for(int i = 1; i <= n; i++){
            adya[i].clear();
            adya2[i].clear();
        }
        cont = 0;
    }
    return 0;
}
