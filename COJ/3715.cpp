#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 10;

int n, m;
int p[MAXn];

struct edge{
    int n1;
    int n2;
    int p;
    bool operator < (const edge &var) const {
        return var.p < p;
    }
}graph[(int)(1e5) + 10];

int find_set(int x){
    if(x == p[x])
        return x;
    return p[x] = find_set(p[x]);
}

bool correct(){
    for(int i = 0; i < n; i++)
        find_set(i);
    for(int i = 1; i < n; i++)
        if(p[i] != p[i - 1]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m){
        if(n == 0 && m == n)
            return 0;
        int sol = 1e8;
        for(int i = 0; i < m; i++){
            cin>>graph[i].n1>>graph[i].n2;
            cin>>graph[i].p;
        }
        sort(graph, graph + m);
        for(int i = 0; i < n; i++)
            p[i] = i;
        for(int i = 0; i < m; i++){
            int n1 = graph[i].n1;
            int n2 = graph[i].n2;
            int set1 = find_set(n1);
            int set2 = find_set(n2);
            if(set1 != set2){
                p[set1] = set2;
                sol = mn(sol, graph[i].p);
            }
        }
        if(correct())
            cout<<sol;
        else
            cout<<"IMPOSSIBLE";
        cout<<"\n";
    }
    return 0;
}
