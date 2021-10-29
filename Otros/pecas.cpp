#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < double , double > par;

par arr[102];

struct arist{
    int n1, n2;
    double val;
    bool operator < (const arist &var) const {
        return var.val > val;
    }
};

vector < arist > edge;
int p[102];

int find_set(int x){
    if(p[x] == x)
        return x;
    return p[x] = find_set(p[x]);
}

int main()
{
    freopen("pecas.in","r",stdin);
    freopen("pecas.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i].f>>arr[i].s;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            double aux = sqrt(((arr[j].f - arr[i].f) * (arr[j].f - arr[i].f)) + ((arr[j].s - arr[i].s) * (arr[j].s - arr[i].s)));
            edge.push_back(arist{i, j, aux});
        }
    }
    sort(all(edge));
    for(int i = 1; i <= n; i++)
        p[i] = i;
    double suma = 0;
    for(auto x: edge){
        int n1 = x.n1, n2 = x.n2;
        double w = x.val;
        int set1 = find_set(n1);
        int set2 = find_set(n2);
        if(set1 != set2){
            p[set1] = set2;
            suma += w;
        }
    }
    cout<<fixed<<setprecision(2)<<suma;
    return 0;
}
