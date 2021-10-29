#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, loga = log2(MAXn) + 2;

int arr[MAXn];
map < int , int > mapa;
int id[MAXn];
int lvl[MAXn];
int padre[MAXn][loga];
int n, q;
vector < int > adya[MAXn];

struct node{
    int val;
    node *left, *right;
    node(int val, node *left, node *right):val(val), left(left), right(right){}
    node *update(int l, int r, int &a);
};

node *null = new node(0, NULL, NULL);

node *node::update(int l ,int r, int &a){
    if(l <= a && a <= r){
        if(l == r)
            return new node(this->val + 1, null, null);
        int mit = (l + r) >> 1;
        node *a1 = this->left->update(l, mit, a);
        node *a2 = this->right->update(mit + 1, r, a);
        return new node(this->val + 1, a1, a2);
    }
    return this;
}

node *PST[MAXn];

void DFS(int v, int p){
    lvl[v] = lvl[p] + 1;
    padre[v][0] = p;
    PST[v] = (p == 0 ? null : PST[p])->update(1, n, mapa[arr[v]]);
    for(int i = 0; i < (int)adya[v].size(); i++)
        if(adya[v][i] != p) DFS(adya[v][i], v);
}

int LCA(int a, int b){
    if(lvl[a] < lvl[b])
        swap(a, b);
    int lg = log2(lvl[a] - 1);
    for(int i = lg; i >= 0; i--){
        if(lvl[padre[a][i]] >= lvl[b])
            a = padre[a][i];
    }
    if(a == b) return a;
    lg = log2(lvl[a] - 1);
    for(int i = lg; i >= 0; i--){
        if(padre[a][i] != padre[b][i]){
            a = padre[a][i];
            b = padre[b][i];
        }
    }
    return padre[a][0];
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k){
    if(l == r)
        return l;
    int mit = (l + r) >> 1;
    int aux = a->left->val + b->left->val - c->left->val - d->left->val;
    if(aux >= k)
        return query(a->left, b->left, c->left, d->left, l, mit, k);
    return query(a->right, b->right, c->right, d->right, mit + 1, r, k - aux);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        mapa[arr[i]];
    }
    for(int i = 1; i < n; i++){
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }
    int con = 0;
    map < int , int > ::iterator it;
    for(it = mapa.begin(); it != mapa.end(); it++){
        mapa[it->f] = ++con;
        id[con] = it->f;
    }
    null->left = null->right = null;
    DFS(1, 0);
    int lg = log2(n - 1);
    for(int e = 1; e <= lg; e++){
        for(int i = 1; i <= n; i++){
            if(log2(lvl[i] - 1) >= e)
                padre[i][e] = padre[padre[i][e - 1]][e - 1];
        }
    }
    while(q--){
        int a, b, k;
        cin>>a>>b>>k;
        int lca = LCA(a, b);
        int aux = query(PST[a], PST[b], PST[lca], (lca == 1 ? null : PST[padre[lca][0]]), 1, n, k);
        cout<<id[aux]<<"\n";
    }
    return 0;
}
