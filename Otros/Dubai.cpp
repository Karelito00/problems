#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 50001, loga = log2(MAXn);

unordered_map < int , vector < int > > mapa;
int RMQ[MAXn][loga];

int main()
{
    freopen("Dubai.in","r",stdin);
    freopen("Dubai.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>RMQ[i][0];
        mapa[RMQ[i][0]].push_back(i);
    }
    for(int e = 1; (1<<e) <= n; e++){
        for(int i = 1; i + (1<<e) - 1 <= n; i++)
            RMQ[i][e] = mx(RMQ[i][e - 1], RMQ[i + (1<<(e - 1))][e - 1]);
    }
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        int lg = log2(b - a + 1);
        int k = mx(RMQ[a][lg], RMQ[b - (1<<lg) + 1][lg]);
        cout<<k<<" ";
        int pos = lower_bound(all(mapa[k]), a) - mapa[k].begin();
        for(; pos < (int)mapa[k].size() && mapa[k][pos] <= b; pos++) cout<<mapa[k][pos]<<" ";
        cout<<"\n";
    }
    return 0;
}
