#include <bits/stdc++.h>

using namespace std;

int tree[400001];
pair <int,int> z[100001];

void build_tree(int l,int r,int nodo){
    if(l==r){
        tree[nodo]=z[l].first;
        z[l].second=nodo;
        return;
    }
    int mid=(l+r)/2;
    build_tree(l,mid,nodo*2);
    build_tree(mid+1,r,nodo*2+1);
    tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
}
int query(int l,int r,int nodo,int a,int b){
    if(l>r || r<a || l>b)
        return 0;
    if(l>=a && r<=b)
        return tree[nodo];
    int mid=(l+r)/2;
    int a1=query(l,mid,nodo*2,a,b);
    int a2=query(mid+1,r,nodo*2+1,a,b);
    return a1+a2;
}
void update(int nodo){
    nodo/=2;
    while(nodo>=1){
        tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
        nodo/=2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n,q;
        cin>>n>>q;
        for(int o=1;o<=n;o++){
            cin>>z[o].first;
        }
        build_tree(1,n,1);
        cout<<"Case "<<i+1<<":\n";
        for(int u=0;u<q;u++){
            int h;
            cin>>h;
            if(h==1){
                int k;
                cin>>k;
                cout<<tree[z[k+1].second]<<"\n";
                tree[z[k+1].second]=0;
                update(z[k+1].second);
            }
            else if(h==2){
                int k2,m1;
                cin>>k2>>m1;
                tree[z[k2+1].second]+=m1;
                update(z[k2+1].second);
            }
            else if(h==3){
                int a21,a22;
                cin>>a21>>a22;
                cout<<query(1,n,1,a21+1,a22+1)<<"\n";
            }
        }
    }
    return 0;
}
