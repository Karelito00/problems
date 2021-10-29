#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1;

struct nod{
    int ini;
    int fin;
    int may;
}tree[MAXn * 4];

int arr[MAXn];

nod une(nod a, nod b, int ini, int mit, int fin){
    nod c = {0, 0, 0};
    if(!a.may) return b;
    if(!b.may) return a;
    c.ini = a.ini, c.fin = b.fin;
    if(arr[mit] < arr[mit + 1]){
        if(a.ini == mit - ini + 1)
            c.ini += b.ini;
        if(b.ini == fin - mit)
            c.fin += a.fin;
        c.may = a.fin + b.ini;
    }
    int aa[] = {a.may, b.may, c.ini, c.fin, a.fin, b.ini};
    for(int i = 0; i < 6; i++) c.may = mx(c.may, aa[i]);
    return c;
}

void build(int nodo, int l, int r){
    if(l == r){
        tree[nodo] = nod{1, 1, 1};
        return;
    }
    int mit = (l + r) / 2;
    build(nodo * 2, l, mit);
    build(nodo * 2 + 1, mit + 1, r);
    tree[nodo] = une(tree[nodo * 2], tree[nodo * 2 + 1], l, mit, r);
}

void update(int nodo, int l, int r, int &a, int &val){
    if(l > a || r < a || l > r)
        return;
    if(l == a && r == a){
        arr[l] = val;
        return;
    }
    int mit = (l + r) / 2;
    update(nodo * 2, l , mit, a, val);
    update(nodo * 2 + 1, mit + 1, r, a, val);
    tree[nodo] = une(tree[nodo * 2], tree[nodo * 2 + 1], l, mit, r);
}

nod query(int nodo, int l, int r, int &a, int &b){
    if(l > b || r < a || l > r)
        return nod{0, 0, 0};
    if(l >= a && r <= b)
        return tree[nodo];
    int mit = (l + r) / 2;
    return une(query(nodo * 2, l, mit, a, b), query(nodo * 2 + 1, mit + 1, r, a, b), l, mit, r);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    while(cin>>n>>q){
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        build(1, 1, n);
        string x;
        int a, b;
        while(q--){
            cin>>x>>a>>b;
            a++;
            if(x == "UPDATE")
                update(1, 1, n, a, b);
            else{
                b++;
                cout<<query(1, 1, n, a, b).may<<"\n";
            }
        }
    }
    return 0;
}
