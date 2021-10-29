#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

map < int , int > mapa;
int id[MAXn];
int arr[MAXn];

struct node{
    int val;
    node *left, *right;
    node(int val, node *left, node *right): val(val), left(left), right(right){}
    node *update(int l, int r, int &a);
};

node *null = new node(0, NULL, NULL);

node *node::update(int l, int r, int &a){
    if(l <= a && r >= a){
        if(l == r)
            return new node(this->val + 1, null, null);
        int mit = (l + r) >> 1;
        return new node(this->val + 1, this->left->update(l, mit, a), this->right->update(mit + 1, r, a));
    }
    return this;
}

node *segment_tree[MAXn];

int query(node *a, node *b, int l, int r, int k){
    if(l == r) return l;
    int mit = (l + r) >> 1;
    int aux = a->left->val - b->left->val;
    if(aux >= k)
        return query(a->left, b->left, l, mit, k);
    return query(a->right, b->right, mit + 1, r, k - aux);
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
        cin>>arr[i];
        mapa[arr[i]];
    }
    int con = 0;
    for(auto x: mapa){
        mapa[x.f] = ++con;
        id[con] = x.f;
    }
    null->right = null->left = null;
    for(int i = 1; i <= n; i++)
        segment_tree[i] = (i == 1 ? null : segment_tree[i - 1])->update(1, n, mapa[arr[i]]);
    while(q--){
        int a, b, k;
        cin>>a>>b>>k;
        int sol = query(segment_tree[b], (a == 1 ? null : segment_tree[a - 1]), 1, n, k);
        cout<<id[sol]<<"\n";
    }
    return 0;
}
