#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 2;

int tree[4 * MAXn];
int lazy[4 * MAXn];

void lazy_p(int nodo, int l, int r){
    tree[nodo] = lazy[nodo];
    if(l != r){
        lazy[nodo * 2] = lazy[nodo];
        lazy[nodo * 2 + 1] = lazy[nodo];
    }
    lazy[nodo] = 0;
}

void update(int nodo, int l, int r, int &a, int &b, int &val){
    if(lazy[nodo]) lazy_p(nodo, l, r);
    if(l > r || l > b || r < a)
        return;
    if(l >= a && r <= b){
        tree[nodo] = val;
        if(l != r){
            lazy[nodo * 2] = val;
            lazy[nodo * 2 + 1] = val;
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nodo * 2, l, mit, a, b, val);
    update(nodo * 2 + 1, mit + 1, r, a, b, val);
}

bool arr[MAXn];

int sol(int nodo, int l, int r){
    if(lazy[nodo]) lazy_p(nodo, l, r);
    if(l == r){
        if(!arr[tree[nodo]]){
            arr[tree[nodo]] = true;
            return 1;
        }
        return 0;
    }
    int mit = (l + r) >> 1;
    return sol(nodo * 2, l, mit) + sol(nodo * 2 + 1, mit + 1, r);
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
        int q;
        cin>>q;
        int con = 0;
        while(q--){
            int a, b;
            cin>>a>>b;
            update(1, 1, MAXn - 2, a, b, ++con);
        }
        arr[0] = true;
        cout<<sol(1, 1, MAXn - 2)<<"\n";
        fill(arr, arr + con + 1, false);
        fill(tree, tree + (4 * (MAXn - 1)), false);
    }
    return 0;
}
