#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 5e4 + 2;

long long arr[MAXn];
long long tree[MAXn * 4];

void build_tree(int nod, int l, int r){
    if(l == r){
        tree[nod] = arr[l];
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

void update(int nod, int l, int r, int &a, int &b){
    if(l > r || l > a || r < a)
        return;
    if(l == a && r == l){
        tree[nod] += b;
        arr[a] += b;
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b);
    update(nod * 2 + 1, mit + 1, r, a, b);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

long long query(int nod, int l, int r, int &a, int &b){
    if(l > r || l > b || r < a)
        return 0;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    return query(nod * 2, l, mit, a, b) + query(nod * 2 + 1, mit + 1, r, a, b);
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
        cin>>type;
        int a, b;
        cin>>a>>b;
        if(type == 1){
            update(1, 1, n, a, b);
            cout<<1<<" "<<arr[a]<<"\n";
        }
        else if(type&1)
            cout<<"Error\n";
        else
            cout<<type<<" "<<query(1, 1, n, a, b)<<"\n";
    }
    return 0;
}
