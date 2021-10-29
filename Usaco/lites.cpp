#include <bits/stdc++.h>

using namespace std;
int tree[400001];
bool lazy[400001];

void lazy_p(int nodo,int l,int r){
    if(lazy[nodo]){
        tree[nodo]=(r-l+1)-tree[nodo];
        if(l!=r){
            lazy[nodo*2]=!lazy[nodo*2];
            lazy[nodo*2+1]=!lazy[nodo*2+1];
        }
        lazy[nodo]=false;
    }
}

void update(int nodo,int l,int r,int a,int b){
    lazy_p(nodo,l,r);
    if(l>b || r<a)
        return;
    if(l>=a && r<=b){
        lazy[nodo]=!lazy[nodo];
        lazy_p(nodo,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(nodo*2,l,mid,a,b);
    update(nodo*2+1,mid+1,r,a,b);
    tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
}

int query(int nodo,int l,int r,int a,int b){
    if(l>b || r<a)
        return 0;
    lazy_p(nodo,l,r);
    if(l>=a && r<=b){
        return tree[nodo];
    }
    int mid=(l+r)/2;
    int a1=query(nodo*2,l,mid,a,b);
    int a2=query(nodo*2+1,mid+1,r,a,b);
    return a1+a2;
}

int main()
{
    freopen("lites.in","r",stdin);
    freopen("lites.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==0){
            update(1,1,n,a,b);
        }
        else
            cout<<query(1,1,n,a,b)<<"\n";
    }
    return 0;
}
