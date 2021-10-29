#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

vector < int > sol;
vector < int > adya[10010];
int dist[10010];
int n;

int mit;

int DFS(int nodo, int p){
    int num = 1;
    int aux = 0;
    bool mark = true;
    for(auto to: adya[nodo]){
        if(to != p){
            dist[to] = dist[nodo] + 1;
            aux = DFS(to, nodo);
            if(aux > mit)
                mark = false;
            num += aux;
        }
    }
    if(mark && n - num <= mit)
        sol.push_back(nodo);
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    mit = n / 2;
    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    DFS(1, -1);
    sort(all(sol));
    for(auto x: sol)
        cout<<x<<"\n";
    return 0;
}
