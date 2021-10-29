#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1;

string arr[MAXn];
string tree[MAXn * 4];
string lazy[MAXn * 4];

void lazy_p(int &nod, int &l, int &r){
    tree[nod] = lazy[nod];
    if(l != r){
        lazy[nod * 2] = lazy[nod];
        lazy[nod * 2 + 1] = lazy[nod];
    }
    lazy[nod].clear();
}

void build_tree(int nod, int l, int r){
    if(l == r){
        tree[nod] = arr[l];
        return;
    }
    int mit = (l + r) >> 1;
    build_tree(nod * 2, l, mit);
    build_tree(nod * 2 + 1, mit + 1, r);
    int tm = mn(tree[nod * 2].size(), tree[nod * 2 + 1].size());
    for(int i = 0; i < tm; i++){
        if(tree[nod * 2][i] != tree[nod * 2 + 1][i]) break;
        tree[nod].push_back(tree[nod * 2][i]);
    }
}

string query(int nod, int l, int r, int &a, int &b){
    if(!lazy[nod].empty()) lazy_p(nod, l, r);
    if(l > b || r < a || l > r)
        return "0";
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    string a1 = query(nod * 2, l, mit, a, b);
    string a2 = query(nod * 2 + 1, mit + 1, r, a, b);
    if(a1 == "0") return a2;
    if(a2 == "0") return a1;
    string tt = "";
    int tm = mn(a1.size(), a2.size());
    for(int i = 0; i < tm; i++){
        if(a1[i] != a2[i]) break;
        tt.push_back(a1[i]);
    }
    return tt;
}

void update(int nod, int l, int r, int &a, int &b, string &val){
    if(!lazy[nod].empty())
        lazy_p(nod, l, r);
    if(l > b || r < a || l > r)
        return;
    if(l >= a && r <= b){
        tree[nod] = val;
        if(l != r){
            lazy[nod * 2] = val;
            lazy[nod * 2 + 1] = val;
        }
        return;
    }
    int mit = (l + r) >> 1;
    update(nod * 2, l, mit, a, b, val);
    update(nod * 2 + 1, mit + 1, r, a, b, val);
    int tm = mn(tree[nod * 2].size(), tree[nod * 2 + 1].size());
    tree[nod].clear();
    for(int i = 0; i < tm; i++){
        if(tree[nod * 2][i] != tree[nod * 2 + 1][i]) break;
        tree[nod].push_back(tree[nod * 2][i]);
    }
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
        if(type == 1)
            cout<<query(1, 1, n, a, b).size()<<"\n";
        else{
            string val;
            cin>>val;
            update(1, 1, n, a, b, val);
        }
    }
    return 0;
}
