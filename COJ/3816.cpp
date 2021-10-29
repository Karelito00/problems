#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < double , double > par;

struct trio{
    int n1;
    int n2;
    double p;
    bool operator < (const trio &var) const {
        return var.p > p;
    }
};

par arr[101];

vector < trio > edge;

double funt(int i, int j){
    return sqrt(((arr[i].f - arr[j].f) * (arr[i].f - arr[j].f)) + ((arr[i].s - arr[j].s) * (arr[i].s - arr[j].s)));
}

int p[101];

int find_set(int x){
    if(p[x] == x)
        return x;
    return p[x] = find_set(p[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i].f>>arr[i].s;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            edge.push_back(trio{i, j, funt(i, j)});
        }
    }
    for(int i = 0; i < n; i++)
        p[i] = i;
    double sol = 0;
    sort(all(edge));
    for(auto e: edge){
        int set1 = find_set(e.n1);
        int set2 = find_set(e.n2);
        if(set1 != set2){
            p[set1] = set2;
            sol += e.p;
        }
    }
    cout<<fixed<<setprecision(2)<<sol;
    return 0;
}
