#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

vector < int > adya[MAXn];
int ord[MAXn];
int qy[MAXn];
int tree[4 * MAXn];
int lazy[4 * MAXn];
int root, con;

int DFS(int v){
    ord[v] = ++con;
    int maxm = con;
    for(auto to: adya[v]){
        int aux = DFS(to);
        maxm = mx(maxm, aux);
    }
    qy[v] = maxm;
    return mx(maxm, con);
}

void lazy_p(int nodo, int l, int r){
    tree[nodo] = lazy[nodo];
    if(l != r){
        lazy[nodo * 2] = lazy[nodo];
        lazy[nodo * 2 + 1] = lazy[nodo];
    }
    lazy[nodo] = 0;
}

void update(int nodo, int l, int r, int &a, int &b, int &val){
    if(lazy[nodo]) lazy_p(nodo, l, r);
    if(l > r || l > b || r < a)
        return;
    if(l >= a && r <= b){
        tree[nodo] = val;
        if(l != r){
            lazy[nodo * 2] = val;
            lazy[nodo * 2 + 1] = val;
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nodo * 2, l, mit, a, b, val);
    update(nodo * 2 + 1, mit + 1, r, a, b, val);
}

unordered_map < int , bool > mapa;

int query_tree(int nodo, int l, int r){
    if(lazy[nodo]) lazy_p(nodo, l ,r);
    if(l == r){
        if(mapa.find(tree[nodo]) == mapa.end()){
            mapa[tree[nodo]] = true;
            return 1;
        }
        return 0;
    }
    int mit = (l + r) >> 1;
    return query_tree(nodo * 2, l, mit) + query_tree(nodo * 2 + 1, mit + 1, r);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        int n1;
        cin>>n1;
        if(!n1){
            root = i;
            continue;
        }
        adya[n1].push_back(i);
    }
    DFS(root);
    while(q--){
        int x, c;
        cin>>x>>c;
        update(1, 1, n, ord[x], qy[x], c);
    }
    mapa[0] = true;
    cout<<query_tree(1, 1, n);
    return 0;
}
