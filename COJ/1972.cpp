#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < int , int > par;
int const MAXn = 1e5 + 2;

int arr[MAXn];
long long tree[4 * MAXn];
long long lazy[4 * MAXn];
vector < int > adya[MAXn];
int con, n;

void lazy_p(int nodo, int l, int r){
    tree[nodo] += lazy[nodo];
    if(l != r){
        lazy[nodo * 2] += lazy[nodo];
        lazy[nodo * 2 + 1] += lazy[nodo];
    }
    lazy[nodo] = 0;
}

void update(int nodo, int l, int r, int &a, int &b, int &val){
    if(lazy[nodo] != 0) lazy_p(nodo, l, r);
    if(l > b || r < a || l > r)
        return;
    if(l >= a && r <= b){
        tree[nodo] += val;
        if(l != r){
            lazy[nodo * 2] += val;
            lazy[nodo * 2 + 1] += val;
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nodo * 2, l, mit, a, b, val);
    update(nodo * 2 + 1, mit + 1, r, a, b, val);
    tree[nodo] = tree[nodo * 2] + tree[nodo * 2 + 1];
}

long long query(int nodo, int l, int r, int a){
    if(lazy[nodo] != 0) lazy_p(nodo, l, r);
    if(l > a || r < a || l > r)
        return 0;
    if(l == a && r == a)
        return tree[nodo];
    int mit = (l + r) / 2;
    long long a1 = query(nodo * 2, l, mit, a);
    long long a2 = query(nodo * 2 + 1, mit + 1, r, a);
    return a1 + a2;
}

int ord[MAXn];
par qy[MAXn];

par DFS(int v){
    ord[v] = ++con;
    update(1, 1, n, con, con, arr[v]);
    int minm = INT_MAX, maxm = 0;
    for(auto to: adya[v]){
        par aux = DFS(to);
        minm = mn(aux.f, minm);
        maxm = mx(aux.s, maxm);
    }
    qy[v] = mp(minm, maxm);
    return mp(mn(minm, ord[v]), mx(maxm, ord[v]));
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    cin>>arr[1];
    for(int i = 2; i <= n; i++){
        cin>>arr[i];
        int n1;
        cin>>n1;
        adya[n1].push_back(i);
    }
    DFS(1);
    while(q--){
        string type;
        cin>>type;
        int a, b;
        cin>>a;
        if(type == "Change"){
            cin>>b;
            update(1, 1, n, qy[a].f, qy[a].s, b);
        }
        else
            cout<<query(1, 1, n, ord[a])<<"\n";
    }
    return 0;
}
