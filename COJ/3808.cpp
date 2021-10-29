#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 3;

struct node{
    int val;
    node *left, *right;
    node(int val, node *left, node *right):val(val), left(left), right(right){}
    node *update(int l, int r, int &a);
};

node *null = new node(0, NULL, NULL);
node *PST[MAXn];
map < int , int > mapa;
int arr[MAXn];
int inv[MAXn];

node *node::update(int l, int r, int &a){
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

int query(node *a, node *b, int l, int r, int k){
    if(l == r)
        return l;
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
    while(cin>>n>>q){
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            mapa[arr[i]];
        }
        int cant = 0;
        for(auto x: mapa){
            mapa[x.f] = ++cant;
            inv[cant] = x.f;
        }
        null->left = null->right = null;
        for(int i = 1; i <= n; i++)
            PST[i] = (i == 1 ? null : PST[i - 1])->update(1, cant, mapa[arr[i]]);
        while(q--){
            int a, b, k;
            cin>>a>>b>>k;
            int aux = query(PST[b], (a == 1 ? null : PST[a - 1]), 1, cant, k);
            cout<<inv[aux]<<"\n";
        }
        mapa.clear();
        fill(PST + 1, PST + n + 1, null);
    }
    return 0;
}
