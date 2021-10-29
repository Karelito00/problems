#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, MAXf = 1e7 + 2, MOD = 1e9 + 7;
typedef long long ll;

int fib[MAXf];
int arr[MAXn];
int tree[MAXn * 4][2];
int lazy[MAXn * 4];

void lazy_p(int &l, int &r, int nod){
    int aux = lazy[nod] - 1;
    int aux0 = (((ll)tree[nod][0] * (ll)fib[aux + 1]) + ((ll)tree[nod][1] * (ll)fib[aux])) % MOD;
    int aux1 = (((ll)tree[nod][0] * (ll)fib[aux]) + ((ll)tree[nod][1] * (ll)fib[aux - 1])) % MOD;
    tree[nod][0] = aux0;
    tree[nod][1] = aux1;
    if(l != r){
        lazy[nod * 2] += aux + 1;
        lazy[nod * 2 + 1] += aux + 1;
    }
    lazy[nod] = 0;
}

void build_tree(int nod, int l, int r){
    if(l == r){
        tree[nod][0] = fib[arr[l]];
        tree[nod][1] = fib[arr[l] - 1];
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    tree[nod][0] = ((ll)tree[nod * 2][0] + (ll)tree[nod * 2 + 1][0]) % MOD;
    tree[nod][1] = ((ll)tree[nod * 2][1] + (ll)tree[nod * 2 + 1][1]) % MOD;
}

long long query(int nod, int l, int r, int &a, int &b){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > r || l > b || r < a)
        return 0;
    if(l >= a && r <= b)
        return tree[nod][0];
    int mit = (l + r) >> 1;
    int a1 = query(nod * 2, l, mit, a, b);
    int a2 = query(nod * 2 + 1, mit + 1, r, a, b);
    return ((ll)a1 + (ll)a2) % MOD;
}

void update(int nod, int l, int r, int &a, int &b, int &val){
    if(lazy[nod]) lazy_p(l, r, nod);
    if(l > r || l > b || r < a)
        return;
    if(l >= a && r <= b){
        lazy[nod] += val;
        if(lazy[nod]) lazy_p(l, r, nod);
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b, val);
    update(nod * 2 + 1, mit + 1, r, a, b, val);
    tree[nod][0] = ((ll)tree[nod * 2][0] + (ll)tree[nod * 2 + 1][0]) % MOD;
    tree[nod][1] = ((ll)tree[nod * 2][1] + (ll)tree[nod * 2 + 1][1]) % MOD;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= MAXf - 2; i++)
        fib[i] = ((ll)fib[i - 1] + (ll)fib[i - 2]) % MOD;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        build_tree(1, 1, n);
        int q;
        cin>>q;
        while(q--){
            short type;
            int a, b;
            cin>>type>>a>>b;
            if(type == 1)
                cout<<query(1, 1, n, a, b)<<"\n";
            else{
                int val;
                cin>>val;
                update(1, 1, n, a, b, val);
            }
        }
        fill(lazy + 1, lazy + (n * 4) + 1, 0);
    }
    return 0;
}
