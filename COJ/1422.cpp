#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

long long tree[4000001];
long long lazy[4000001];

void lazy_p(int nodo,int l,int r){
    if(lazy[nodo]!=0){
        tree[nodo]=(tree[nodo]*lazy[nodo])%MOD;
        if(l!=r){
            if(lazy[nodo*2]!=0)
                lazy[nodo*2] = (lazy[nodo*2]*lazy[nodo])%MOD;
            else
                lazy[nodo*2] = lazy[nodo]%MOD;
            if(lazy[nodo*2+1]!=0)
                lazy[nodo*2+1] = (lazy[nodo*2+1]*lazy[nodo])%MOD;
            else
                lazy[nodo*2+1] = lazy[nodo]%MOD;
        }
        lazy[nodo]=0;
    }
}

void build_tree(int nodo,int l,int r){
     lazy[nodo]=0;
    if(l==r){
        tree[nodo]=1;
        return;
    }
    int mid=(l+r)/2;
    build_tree(nodo*2,l,mid);
    build_tree(nodo*2+1,mid+1,r);
    tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
}
long long query(int nodo,int l,int r,int a,int b){
    if(l>b || r<a)
        return 0;
    lazy_p(nodo,l,r);
    if(l>=a && r<=b){
        return tree[nodo]%MOD;
    }
    int mid=(l+r)/2;
    long long a1=query(nodo*2,l,mid,a,b)%MOD;
    long long a2=query(nodo*2+1,mid+1,r,a,b)%MOD;
    return (a1+a2)%MOD;
}
void update(int nodo,int l,int r,int a,int b,int val){
    if(lazy[nodo]!=0)
        lazy_p(nodo,l,r);
    if(l>b || r<a)
        return;
    if(l>=a && r<=b){
        if(lazy[nodo]!=0)
            lazy[nodo] = (lazy[nodo]*val)%MOD;
        else
            lazy[nodo] = val;
        lazy_p(nodo,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(nodo*2,l,mid,a,b,val);
    update(nodo*2+1,mid+1,r,a,b,val);
    tree[nodo]=(tree[nodo*2]+tree[nodo*2+1])%MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        build_tree(1,1,n);
        for(int u=0;u<m;u++){
            long long t,x,y,k;
            cin>>t>>x>>y;
            if(t==1){
                cout<<query(1,1,n,x,y)<<"\n";
            }
            else{
                cin>>k;
                k=k%MOD;
                update(1,1,n,x,y,k);
            }
        }
    }
    return 0;
}
