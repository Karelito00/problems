#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

int arr[MAXn];

struct nod{
    bool creciente;
    bool no_decr;
}tree[MAXn * 4];

nod une(nod a, nod b, int mit){
    nod c;
    if(a.creciente && b.creciente){
        if(arr[mit] < arr[mit + 1])
            c.creciente = true, c.no_decr = false;
        else if(arr[mit] == arr[mit + 1])
            c.creciente = false, c.no_decr = true;
        else
            c.creciente = false, c.no_decr = false;
    }
    else if(a.no_decr && b.no_decr){
        if(arr[mit] <= arr[mit + 1])
            c.creciente = false, c.no_decr = true;
        else
            c.creciente = c.no_decr = false;
    }
    else if((a.creciente && b.no_decr) || (b.creciente && a.no_decr)){
        if(arr[mit] <= arr[mit + 1])
            c.creciente = false, c.no_decr = true;
        else
            c.creciente = c.no_decr = false;
    }
    else
        c.creciente = c.no_decr = false;
    return c;
}

void build_tree(int nodo, int l, int r){
    if(l == r){
        tree[nodo].creciente = true;
        tree[nodo].no_decr = false;
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nodo * 2, l, mit);
    build_tree(nodo * 2 + 1, mit + 1, r);
    tree[nodo] = une(tree[nodo * 2], tree[nodo * 2 + 1], mit);
}

void update(int nodo, int l, int r, int &pos, int &val){
    if(l > r || l > pos || r < pos)
        return;
    if(l == r){
        arr[l] = val;
        return;
    }
    int mit = (l + r) >> 1;
    update(nodo * 2, l, mit, pos, val);
    update(nodo * 2 + 1, mit + 1, r, pos, val);
    tree[nodo] = une(tree[nodo * 2], tree[nodo * 2 + 1], mit);
}

nod query(int nodo, int l, int r, int &a, int &b){
    if(l > r || l > b || r < a)
        return nod{true, true};
    if(l >= a && r <= b)
        return tree[nodo];
    int mit = (l + r) >> 1;
    nod a1 = query(nodo * 2, l, mit, a, b);
    nod a2 = query(nodo * 2 + 1, mit + 1, r, a, b);
    if(a1.creciente && a1.no_decr)
        return a2;
    else if(a2.creciente && a2.no_decr)
        return a1;
    return une(a1, a2, mit);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    build_tree(1, 1, n);
    while(q--){
        short type;
        int a, b;
        cin>>type>>a>>b;
        if(type == 1)
            update(1, 1, n, a, b);
        else{
            nod aux = query(1, 1, n, a, b);
            if(aux.creciente) cout<<2;
            else if(aux.no_decr) cout<<1;
            else cout<<0;
            cout<<"\n";
        }
    }
    return 0;
}
