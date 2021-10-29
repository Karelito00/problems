#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define MAX 999999999
#define mn(a,b) (a < b ? a : b)

using namespace std;

typedef pair < int , int > par;
int const MAXn = 3000;
int s1,n,m;
vector < pair < int , par > > adya[MAXn+5];
int dist[3001][2001];

int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>n>>m;
    for(int i=0;i<m;i++){
        int n1,n2,t,c;
        cin>>n1>>n2>>t>>c;
        n1--,n2--;
        adya[n1].push_back(mp(n2,mp(t,c)));
        adya[n2].push_back(mp(n1,mp(t,c)));
    }
    for(int i=1;i<n;i++)
        fill(dist[i],dist[i]+s1+1,MAX);

    queue < par > cola;
    cola.push(mp(0,0));
    while(!cola.empty()){
        par v = cola.front();
        cola.pop();
        for(int i=0;i<(int)adya[v.f].size();i++){
            int to = adya[v.f][i].f;
            int time = adya[v.f][i].s.f;
            int cost = adya[v.f][i].s.s;
            if(cost + v.s > s1)  continue;
            if(dist[to][cost + v.s] > dist[v.f][v.s] + time){
                dist[to][cost + v.s] = dist[v.f][v.s] + time;
                cola.push(mp(to,cost+v.s));
            }
        }
    }
    int best = MAX;
    for(int i=0;i<=s1;i++){
        best = mn(best , dist[n-1][i]);
    }
    cout<<(best == MAX ? -1 : best);
    return 0;
}
