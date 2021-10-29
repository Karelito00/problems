#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 3e4 + 2, MAXq = 2e5 + 2;

int tree[4 * MAXn];
int cc;

struct gg{
    int id;
    int a, b;
    int k;
    bool operator < (const gg &var) const {
        if(var.k == k)
            return var.id < id;
        return var.k < k;
    }
}greedy[MAXn + MAXq];

int arr[MAXn];

void update(int l, int r, int nod, int &a){
    if(l > r || l > a || r < a)
        return;
    if(l == a && l == r){
        tree[nod]++;
        return;
    }
    int mit = (l + r) >> 1;
    update(l, mit, nod * 2, a);
    update(mit + 1, r, nod * 2 + 1, a);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

int query(int nod, int l, int r, int &a, int &b){
    if(l > r || l > b || r < a)
        return 0;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    return query(nod * 2, l, mit, a, b) + query(nod * 2 + 1, mit + 1, r, a, b);
}

int sol[MAXq];

int main()
{
    freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        greedy[++cc] = gg{0, i, i, arr[i]};
    }
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
        int a1, b1, k1;
        cin>>a1>>b1>>k1;
        greedy[++cc] = gg{i, a1, b1, k1};
    }
    sort(greedy + 1, greedy + cc + 1);
    for(int i = 1; i <= cc; i++){
        if(greedy[i].id == 0)
            update(1, n, 1, greedy[i].a);
        else
            sol[greedy[i].id] = query(1, 1, n, greedy[i].a, greedy[i].b);
    }
    for(int i = 1; i <= q; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
