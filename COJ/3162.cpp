#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 2e5 + 2;

struct nodo{
    int open;
    int close;
};

struct st{
    nodo l[2];
}tree[4 * MAXn];

int lazy[MAXn * 4];
char arr[MAXn];

void lazy_p(int l, int r, int nod){
    if(lazy[nod] % 2 != 0)
        swap(tree[nod].l[0], tree[nod].l[1]);
    if(l != r){
        lazy[nod * 2] += lazy[nod];
        lazy[nod * 2 + 1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void build_tree(int nod, int l, int r){
    if(l == r){
        if(arr[l] == '('){
            tree[nod].l[0].open++;
            tree[nod].l[1].close++;
        }
        else{
            tree[nod].l[0].close++;
            tree[nod].l[1].open++;
        }
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    int aux = mn(tree[nod * 2].l[0].open, tree[nod * 2 + 1].l[0].close);
    tree[nod].l[0].open = tree[nod * 2].l[0].open + tree[nod * 2 + 1].l[0].open - aux;
    tree[nod].l[0].close = tree[nod * 2].l[0].close + tree[nod * 2 + 1].l[0].close - aux;
    aux = mn(tree[nod * 2].l[1].open, tree[nod * 2 + 1].l[1].close);
    tree[nod].l[1].open = tree[nod * 2].l[1].open + tree[nod * 2 + 1].l[1].open - aux;
    tree[nod].l[1].close = tree[nod * 2].l[1].close + tree[nod * 2 + 1].l[1].close - aux;
}

nodo query(int nod, int l, int r, int &a, int &b){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > r || r < a || l > b)
        return nodo{0, 0};
    if(l >= a && r <= b)
        return tree[nod].l[0];
    int mit = (l + r) >> 1;
    nodo a1 = query(nod * 2, l, mit, a, b);
    nodo a2 = query(nod * 2 + 1, mit + 1, r, a, b);
    nodo a3;
    int aux = mn(a1.open, a2.close);
    a3.open = a1.open + a2.open - aux;
    a3.close = a1.close + a2.close - aux;
    return a3;
}

void update(int nod, int l, int r, int a, int b){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > r || r < a || l > b)
        return;
    if(l >= a && r <= b){
        lazy[nod]++;
        lazy_p(l, r, nod);
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b);
    update(nod * 2 + 1, mit + 1, r, a, b);
    int aux = mn(tree[nod * 2].l[0].open, tree[nod * 2 + 1].l[0].close);
    tree[nod].l[0].open = tree[nod * 2].l[0].open + tree[nod * 2 + 1].l[0].open - aux;
    tree[nod].l[0].close = tree[nod * 2].l[0].close + tree[nod * 2 + 1].l[0].close - aux;
    aux = mn(tree[nod * 2].l[1].open, tree[nod * 2 + 1].l[1].close);
    tree[nod].l[1].open = tree[nod * 2].l[1].open + tree[nod * 2 + 1].l[1].open - aux;
    tree[nod].l[1].close = tree[nod * 2].l[1].close + tree[nod * 2 + 1].l[1].close - aux;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    build_tree(1, 1, n);
    int q;
    cin>>q;
    while(q--){
        char type;
        int a, b;
        cin>>type>>a>>b;
        if(type == 'q'){
            nodo aux = query(1, 1, n, a, b);
            if(aux.open == aux.close && !aux.open) cout<<1;
            else cout<<0;
            cout<<"\n";
        }
        else
            update(1, 1, n, a, b);
    }
    return 0;
}
