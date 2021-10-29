#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int const MAXn = 2e5 + 2;

struct query{
    char x;
    int val;
}q[MAXn];
int id;
int con;

map < int , int > mapa;

int tree[4 * MAXn];
int rev[MAXn];
bool mark[MAXn];

void update(int l, int r, int nod, int &a, int val){
    if(l > a || r < a || l > r)
        return;
    if(l == a && r == l){
        tree[nod] += val;
        return;
    }
    int mit = (l + r) >> 1;
    update(l, mit, nod * 2, a, val);
    update(mit + 1, r, nod * 2 + 1, a, val);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

int query1(int l, int r, int k, int nod){
    if(l == r)
        return l;
    int mit = (l + r) >> 1;
    if(tree[nod * 2] >= k)
        return query1(l, mit, k, nod * 2);
    else
        return query1(mit + 1, r, k - tree[nod * 2], nod * 2 + 1);
}

int query2(int l, int r, int nod, int &b){
    if(l > b || r < 1 || l > r)
        return 0;
    if(l >= 1 && r <= b)
        return tree[nod];
    int mit = (l + r) >> 1;
    return query2(l, mit, nod * 2, b) + query2(mit + 1, r, nod * 2 + 1, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        char x;
        int val;
        cin>>x>>val;
        mapa[val];
        q[i] = query{x, val};
    }
    for(auto x: mapa){
        mapa[x.f] = ++id;
        rev[id] = x.f;
    }
    for(int i = 1; i <= n; i++){
        int aux = mapa[q[i].val];
        if(q[i].x == 'I'){
            if(!mark[aux]){
                con++;
                mark[aux] = true;
                update(1, id, 1, aux, 1);
            }
            continue;
        }
        else if(q[i].x == 'D'){
            if(mark[aux]){
                mark[aux] = false;
                con--;
                update(1, id, 1, aux, -1);
            }
            continue;
        }
        else if(q[i].x == 'K'){
            if(con < q[i].val)
                cout<<"invalid";
            else
                cout<<rev[query1(1, id, q[i].val, 1)];
        }
        else{
            int sol = query2(1, id, 1, aux);
            cout<<sol - (mark[aux] ? 1 : 0);
        }
        cout<<"\n";
    }
    return 0;
}
