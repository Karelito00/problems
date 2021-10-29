#include <bits/stdc++.h>

using namespace std;

int const MAXn = 5e4 + 1, NUM = 1e6 + 1;

int arr[MAXn];
set < int > num[NUM];
int tree[4 * MAXn];

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
    tree[nod] = max(tree[nod * 2], tree[nod * 2 + 1]);
}

int query(int nod, int l, int r, int &a, int &b){
    if(l > b || r < a || l > r)
        return 0;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    return max(query(nod * 2, l, mit, a, b), query(nod * 2 + 1, mit + 1, r, a, b));
}

int o, pp = 1, nu, ax;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];

    for(int i = n; i >= 1; i--){
        auto x = num[arr[i]].upper_bound(i);
        if(x != num[arr[i]].end()){
            o = *x;
            update(1, 1, n, o, i);
        }
        num[arr[i]].insert(i);
    }
    int pos;
    char x;
    while(q--){
        cin>>x>>pos;
        if(x == 'E'){
            o = pos;
            cout<<pos - query(1, 1, n, pp, o)<<"\n";
        }
        else{
            int val;
            cin>>val;
            auto aux = num[arr[pos]].upper_bound(pos);
            if(aux != num[arr[pos]].end()){
                o = *aux;
                ax = query(1, 1, n, pos, pos);
                update(1, 1, n, o, ax);
            }
            update(1, 1, n, pos, nu);
            num[arr[pos]].erase(pos);
            arr[pos] = val;
            aux = num[arr[pos]].upper_bound(pos);
            if(aux != num[arr[pos]].end()){
                o = *aux;
                update(1, 1, n, o, pos);
            }
            num[arr[pos]].insert(pos);
            aux = num[arr[pos]].lower_bound(pos);
            if(aux != num[arr[pos]].begin()){
                aux--;
                o = *aux;
                update(1, 1, n, pos, o);
            }
        }
    }
    return 0;
}
