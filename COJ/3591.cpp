#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

char arr[MAXn];
short pot[MAXn];
short tree[4 * MAXn];

void build_tree(int nod, int l, int r){
    if(l == r){
        if(arr[l] == '1')
            tree[nod] = pot[l - 1];
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    tree[nod] = (tree[nod * 2] + tree[nod * 2 + 1]) % 3;
}

void update(int nod, int l, int r, int &a, int &val){
    if(l > a || r < a || l > r)
        return;
    if(l == a && r == a){
        tree[nod] = val;
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, val);
    update(nod * 2 + 1, mit + 1, r, a, val);
    tree[nod] = (tree[nod * 2] + tree[nod * 2 + 1]) % 3;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = n; i >= 1; i--)
        cin>>arr[i];
    pot[0] = 1;
    for(int i = 1; i < n; i++)
        pot[i] = (pot[i - 1] * 2) % 3;
    build_tree(1, 1, n);
    while(q--){
        int a, b, val;
        char type;
        cin>>type;
        if(type == 'P'){
            cout<<(!tree[1] ? "Yes" : "No")<<"\n";
        }
        else if(type == 'C'){
            cin>>a;
            a++;
            if(arr[a] == '0'){
                arr[a] = '1';
                val = pot[a - 1];
            }
            else{
                arr[a] = '0';
                val = 0;
            }
            update(1, 1, n, a, val);
        }
        else{
            cin>>a>>b;
            a++;
            if(arr[a] - '0' == b)
                continue;
            arr[a] = b + '0';
            val = (!b ? 0 : pot[a - 1]);
            update(1, 1, n, a, val);
        }
    }
    return 0;
}
