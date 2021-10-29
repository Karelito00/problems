#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1;

struct nodo{
    int d[10];
}tree[4 * MAXn], lazy[4 * MAXn];

int arr[MAXn][10];

void lazy_p(int nod, int l, int r){
    bool reb = false;
    for(int i = 0; i < 10; i++)
        if(lazy[nod].d[i]) reb = true;
    if(!reb) return;
    for(int i = 0; i < 10; i++)
        tree[nod].d[i] = lazy[nod].d[i] * (r - l + 1);
    if(l != r){
        for(int i = 0; i < 10; i++){
            lazy[nod * 2].d[i] = lazy[nod].d[i];
            lazy[nod * 2 + 1].d[i] = lazy[nod].d[i];
        }
    }
    for(int i = 0; i < 10; i++) lazy[nod].d[i] = 0;
}

void build(int nod, int l, int r){
    if(l == r){
        for(int i = 0; i < 10; i++)
            tree[nod].d[i] = arr[l][i];
        return;
    }
    int mit = (l + r) / 2;
    build(nod * 2, l, mit);
    build(nod * 2 + 1, mit + 1, r);
    for(int i = 0; i < 10; i++)
        tree[nod].d[i] = tree[nod * 2].d[i] + tree[nod * 2 + 1].d[i];
}

nodo null_0;

nodo query(int nod, int l, int r, int &a, int &b){
    lazy_p(nod, l, r);
    if(l > r || l > b || r < a)
        return null_0;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    nodo a1 = query(nod * 2, l, mit, a, b);
    nodo a2 = query(nod * 2 + 1, mit + 1, r, a, b);
    nodo a3;
    for(int i = 0; i < 10; i++)
        a3.d[i] = a1.d[i] + a2.d[i];
    return a3;
}

void update(int nod, int l, int r, int &a, int &b, nodo &val){
    lazy_p(nod, l, r);
    if(l > r || l > b || r < a)
        return;
    if(l >= a && r <= b){
        for(int i = 0; i < 10; i++)
            tree[nod].d[i] = (val.d[i] * (r - l + 1));
        if(l != r){
            for(int i = 0; i < 10; i++){
                lazy[nod * 2].d[i] = val.d[i];
                lazy[nod * 2 + 1].d[i] = val.d[i];
            }
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b, val);
    update(nod * 2 + 1, mit + 1, r, a, b, val);
    for(int i = 0; i < 10; i++)
        tree[nod].d[i] = tree[nod * 2].d[i] + tree[nod * 2 + 1].d[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        for(auto x: s)
            arr[i][x - '0']++;
    }
    build(1, 1, n);
    while(q--){
        bool type;
        int a, b;
        string val;
        cin>>type>>a>>b;
        if(!type){
            int ind = 0;
            nodo aux = query(1, 1, n, a, b);
            for(int i = 1; i < 10; i++)
                if(aux.d[i] > aux.d[ind]) ind = i;
            cout<<ind<<"\n";
        }
        else{
            cin>>val;
            nodo aux = null_0;
            for(auto x: val) aux.d[x - '0']++;
            update(1, 1, n, a, b, aux);
        }
    }
    return 0;
}
