#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int z[100001];
ll tree[400001];
void build_tree(int l,int r,int nodo){
    if(l==r){
        tree[nodo]=z[l];
        return;
    }
    build_tree(l,(l+r)/2,nodo*2);
    build_tree((l+r)/2+1,r,nodo*2+1);
    tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
}
ll query(int l,int r,int nodo,int a,int b){
    if(l>r || l>b || r<a)
        return 0;
    if(l>=a && r<=b)
        return tree[nodo];
    ll a1=query(l,(l+r)/2,nodo*2,a,b);
    ll a2=query((l+r)/2+1,r,nodo*2+1,a,b);
    return a1+a2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>z[i];
        }
        build_tree(1,n,1);
        for(int u=0;u<q;u++){
            int d1,d2;
            cin>>d1>>d2;
            d1++,d2++;
            if(b==a-1 && u==q-1)
                cout<<query(1,n,1,d1,d2);
            else
                cout<<query(1,n,1,d1,d2)<<"\n";
        }
        if(b!=a-1)
            cout<<"\n";
    }
    return 0;
}
