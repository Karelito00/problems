#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define trio pair < int , pair < int , int > >

using namespace std;

trio edge[5000];

struct cmp{
public:
    bool operator () (const trio &one, const trio &two) const {
        return one.f < two.f;
    }
};

int p[110];

int find_set(int x){
    if(p[x] == x)
        return x;
    return p[x] = find_set(p[x]);
}
vector < int > adya[110];
bool visited[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
        cin>>edge[i].s.f>>edge[i].s.s>>edge[i].f;

    sort(edge, edge + m, cmp());

    for(int i = 1; i <= n; i++)
        p[i] = i;

    int sum = 0;
    for(int i = 0; i < m; i++){
        int n1 = edge[i].s.f;
        int n2 = edge[i].s.s;
        int set1 = find_set(n1);
        int set2 = find_set(n2);
        if(set1 != set2){
            p[set1] = set2;
            adya[n1].push_back(n2);
            adya[n2].push_back(n1);
            sum += edge[i].f;
        }
    }
    cout<<sum<<"\n";
    queue < int > cola;
    visited[1] = true;
    cola.push(1);
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        bool mark = false;
        for(auto x: adya[v]){
            if(!visited[x]){
                mark = true;
                break;
            }
        }
        if(!mark) continue;
        cout<<v<<" ";
        for(auto x: adya[v]){
            if(!visited[x]){
                visited[x] = true;
                cout<<x<<" ";
                cola.push(x);
            }
        }
        cout<<"\n";
    }
    return 0;
}
