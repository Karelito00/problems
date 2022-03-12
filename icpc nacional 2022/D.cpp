#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
typedef long long ll;

using namespace std;

int const MAXn = 1e5 + 2;

int arr[MAXn];
vector < int > adya[MAXn];
int init[MAXn];
int fin[MAXn];
int inver[MAXn];
int cnt;
int pp[MAXn];


void euler_tour() {
    stack <int> pila;
    pila.push(1);
    stack <int> pila2;
    while(!pila.empty()) {
        int v = pila.top();
        pila2.push(v);
        init[v] = ++cnt;
        fin[v] = cnt;
        inver[cnt] = v;
        pila.pop();
        for(auto u: adya[v]) {
            if(pp[v] == u) continue;
            pila.push(u);
            pp[u] = v;
        }
    }
    while(!pila2.empty()) {
        int v = pila2.top();
        pila2.pop();
        for(auto u: adya[v]) {
            if(pp[v] == u) continue;
            fin[v] = max(fin[v], fin[u]);
        }
    }
}

int tree[MAXn * 4][65];
int lazy[MAXn * 4];

void lazy_p(int nod, int l, int r) {
    if(!lazy[nod]) return;
    int new_arr[65];
    for(int i = 0; i < 64; i++) {
        int x = (i + lazy[nod]) % 64;
        new_arr[x] = tree[nod][i];
    }
    for(int i = 0; i < 64; i++)
        tree[nod][i] = new_arr[i];
    if(l != r) {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1 | 1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod, int l, int r, int a, int b) {
    lazy_p(nod, l, r);
    if(l > b || r < a || l > r) return;
    if(l >= a && r <= b) {
        lazy[nod] += 1;
        lazy_p(nod, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(nod << 1, l, mid, a, b),
    update(nod << 1 | 1, mid + 1, r, a, b);
    for(int i = 0; i < 64; i++)
        tree[nod][i] = tree[nod << 1][i] + tree[nod << 1 | 1][i];
}

int query(int nod, int l, int r, int a, int b, int c) {
    lazy_p(nod, l, r);
    if(l > b || r < a || l > r) return 0;
    if(l >= a && r <= b) {
        return tree[nod][c];
    }
    int mid = (l + r) >> 1;
    int a1 = query(nod << 1, l, mid, a, b, c);
    int a2 = query(nod << 1 | 1, mid + 1, r, a, b, c);
    return a1 + a2;
}

void build_tree(int nod, int l, int r) {
    if(l == r) {
        int x = inver[l];
        tree[nod][arr[x]] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(nod << 1, l, mid),
    build_tree(nod << 1 | 1, mid + 1, r);
    for(int i = 0; i < 64; i++)
        tree[nod][i] = tree[nod << 1][i] + tree[nod << 1 | 1][i];
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++) {
        cin>>arr[i];
    }

    for(int i = 1; i < n; i++) {
        int n1, n2;
        cin>>n1>>n2;
        adya[n1].push_back(n2);
        adya[n2].push_back(n1);
    }

    euler_tour();
    build_tree(1, 1, n);


    while(q--) {
        int t, v;
        cin>>t>>v;

        int a = init[v], b = fin[v];

        if(t == 1) {
            update(1, 1, n, a, b);
        }

        if(t == 2) {
            int c;
            cin>>c;
            cout<<query(1, 1, n, a, b, c)<<"\n";
        }
    }

    return 0;
}
