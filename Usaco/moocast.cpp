#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < pair < int , int > , int > trio;
int const MAXn = 1e3 + 2;

struct cmp{
    bool operator () (const trio &a, const trio &b) const {
        return a.s < b.s;
    }
};

pair < int , int > arr[MAXn];
vector < trio > edge;

int p[1001];

int find_set(int x){
    if(x == p[x]) return x;
    return p[x] = find_set(p[x]);
}

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i].f>>arr[i].s;
    int sol = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            long long aux1 = arr[j].f - arr[i].f;
            long long aux2 = arr[j].s - arr[i].s;
            edge.push_back(mp(mp(i, j), (aux1 * aux1) + (aux2 * aux2)));
        }
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(all(edge), cmp());
    for(auto e: edge){
        int n1 = e.f.f, n2 = e.f.s, w = e.s;
        int set1 = find_set(n1);
        int set2 = find_set(n2);
        if(set1 != set2){
            p[set1] = set2;
            sol = mx(sol, w);
        }
    }
    cout<<sol;
    return 0;
}
