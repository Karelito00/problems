#include <bits/stdc++.h>

using namespace std;

int z[100001];
set < int > tree[400001];

void build_tree(int nodo,int l,int r){
    if(l == r){
        tree[nodo].clear();
        tree[nodo].insert(z[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(nodo*2,l,mid);
    build_tree(nodo*2+1,mid+1,r);
    tree[nodo].clear();
    for(auto x: tree[nodo*2])
        tree[nodo].insert(x);
    for(auto x: tree[nodo*2+1])
        tree[nodo].insert(x);
}

set < int > basura;

set < int > query(int nodo,int l,int r,int a,int b){
    if(l > r || l > b || r < a)
        return basura;
    if(l>=a && r<=b)
        return tree[nodo];
    int mid = (l + r) >> 1;
    set < int > a1 = query(nodo*2,l,mid,a,b);
    set < int > a2 = query(nodo*2+1,mid+1,r,a,b);
    for(auto x: a2){
        a1.insert(x);
    }
    return a1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>z[i];
        }
        build_tree(1,1,n);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b).size()<<"\n";
        }
    }
    return 0;
}

