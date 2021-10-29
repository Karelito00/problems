#include <bits/stdc++.h>
#define mx(a, b) (a > b ? a : b)
#define mn(a, b) (a < b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 5;
typedef pair < long long , long long > par;

vector < int > adya[MAXn];
par tree[4 * MAXn];
long long lazy[4 * MAXn];
int ord[MAXn];
int ord2[MAXn];
int query[MAXn];
int arr[MAXn];
int con, n;

void lazy_p(int l, int r, int nod){
    tree[nod].f += lazy[nod];
    tree[nod].s += lazy[nod];
    if(l != r){
        lazy[nod * 2] += lazy[nod];
        lazy[nod * 2 + 1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod, int l, int r, int a, int b, int val){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > b || r < a || l > r)
        return;
    if(l >= a && r <= b){
        tree[nod].f += val;
        tree[nod].s += val;
        if(l != r){
            lazy[nod * 2] += val;
            lazy[nod * 2 + 1] += val;
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b, val);
    update(nod * 2 + 1, mit + 1, r, a, b, val);
    tree[nod].f = mx(tree[nod * 2].f, tree[nod * 2 + 1].f);
    tree[nod].s = mn(tree[nod * 2].s, tree[nod * 2 + 1].s);
}

par null = mp(-(1LL * INT_MAX * INT_MAX), 1LL * INT_MAX * INT_MAX);

par queryt(int nod, int l, int r, int a, int b){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > r || r < a || l > b)
        return null;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    par a1 = queryt(nod * 2, l, mit, a, b);
    par a2 = queryt(nod * 2 + 1, mit + 1, r, a, b);
    return mp(mx(a1.f, a2.f), mn(a1.s, a2.s));
}

void DFS(){
    stack < int > pila;
    pila.push(1);
    while(!pila.empty()){
        int v = pila.top();
        pila.pop();
        ord[v] = ++con;
        ord2[con] = v;
        for(auto to: adya[v])
            pila.push(to);
    }
    for(int i = con; i >= 1; i--){
        for(auto to: adya[ord2[i]])
            query[ord2[i]] += query[to];
        query[ord2[i]]++;
    }
}

void build_tree(int nod, int l, int r){
    if(l == r){
        tree[nod].f = arr[l];
        tree[nod].s = arr[l];
        lazy[nod] = 0;
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    tree[nod].f = mx(tree[nod * 2].f, tree[nod * 2 + 1].f);
    tree[nod].s = mn(tree[nod * 2].s, tree[nod * 2 + 1].s);
    lazy[nod] = 0;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 2; i <= n; i++){
            int n1;
            cin>>n1;
            adya[n1].push_back(i);
        }
        DFS();
        for(int i = 1; i <= n; i++)
            cin>>arr[ord[i]];
        build_tree(1, 1, n);
        int q;
        cin>>q;
        while(q--){
            char type;
            cin>>type;
            int a, b;
            cin>>a;
            if(type == 'Q'){
                par aux = queryt(1, 1, n, ord[a], ord[a] + query[a] - 1);
                cout<<aux.f - aux.s<<"\n";
            }
            else{
                cin>>b;
                update(1, 1, n, ord[a], ord[a] + query[a] - 1, b);
            }
        }
        fill(query + 1, query + n + 1, 0);
        con = 0;
        for(int i = 1; i <= n; i++)
            adya[i].clear();
    }
    return 0;
}
