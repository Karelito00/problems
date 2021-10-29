#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;
typedef pair < long long , long long > par;

long long ABI[MAXn];
int n;

void update(int pos, long long val){
    while(pos <= n){
        ABI[pos] += val;
        pos += (pos & -pos);
    }
}

long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += ABI[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

par coor[MAXn];
int arr[MAXn];

int tree[MAXn * 4];

void update_tree(int nod, int l, int r, int a){
    if(l > r || l > a || r < a)
        return;
    if(l == a && r == a){
        tree[nod] = arr[l];
        return;
    }
    int mit = (l + r) >> 1;
    update_tree(nod * 2, l, mit, a);
    update_tree(nod * 2 + 1, mit + 1, r, a);
    tree[nod] = mx(tree[nod * 2], tree[nod * 2 + 1]);
}

long long query_tree(int nod, int l, int r, int a, int b){
    if(l > r || l > b || r < a)
        return 0;
    if(l >= a && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    long long a1 = query_tree(nod * 2, l, mit, a, b);
    long long a2 = query_tree(nod * 2 + 1, mit + 1, r, a, b);
    return mx(a1, a2);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>coor[i].f>>coor[i].s;
        if(i >= 2)
            update(i, abs(coor[i].f - coor[i - 1].f) + abs(coor[i].s - coor[i - 1].s));
    }
    for(int i = 2; i < n; i++){
        long long aux = query(i + 1) - query(i - 1);
        arr[i] = aux - (abs(coor[i + 1].f - coor[i - 1].f) + abs(coor[i + 1].s - coor[i - 1].s));
        update_tree(1, 1, n, i);
    }
    while(q--){
        char type;
        cin>>type;
        if(type == 'Q'){
            int a, b;
            cin>>a>>b;
            long long aux = query(b) - query(a);
            cout<<aux - query_tree(1, 1, n, a + 1, b - 1)<<"\n";
        }
        else{
            int pos;
            int x, y;
            cin>>pos>>x>>y;
            long long aux = 0;
            if(pos >= 2){
                aux = abs(x - coor[pos - 1].f) + abs(y - coor[pos - 1].s);
                update(pos, -(abs(coor[pos].f - coor[pos - 1].f) + abs(coor[pos].s - coor[pos - 1].s)) + aux);
            }
            if(pos < n){
                aux = abs(coor[pos + 1].f - x) + abs(coor[pos + 1].s - y);
                update(pos + 1, -(abs(coor[pos + 1].f - coor[pos].f) + abs(coor[pos + 1].s - coor[pos].s)) + aux);
            }
            coor[pos] = mp(x, y);
            for(int i = pos - 1; i < n && i - pos <= 1; i++){
                if(pos <= 1) continue;
                long long aux = query(i + 1) - query(i - 1);
                arr[i] = aux - (abs(coor[i + 1].f - coor[i - 1].f) + abs(coor[i + 1].s - coor[i - 1].s));
                update_tree(1, 1, n, i);
            }
        }
    }
    return 0;
}
