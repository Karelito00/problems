#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

pair <int,int> tree[MAX*4];
int z[MAX];
void build_tree(int l, int r, int nodo){
    if(l==r){
        tree[nodo].first=z[l];
        tree[nodo].second=z[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(l,mid,nodo*2);
    build_tree(mid+1,r,nodo*2+1);
    tree[nodo].first=max(tree[nodo*2].first,tree[nodo*2+1].first);
    tree[nodo].second=min(tree[nodo*2].second,tree[nodo*2+1].second);
}
int query_min(int nodo, int l, int r, int a, int b){
    if(l>r || l>b || r<a)
        return 99999999;
    if(l>=a && r<=b)
        return tree[nodo].second;
    int mid=(l+r)/2;
    int a1=query_min(nodo*2,l,mid,a,b);
    int a2=query_min(nodo*2+1,mid+1,r,a,b);
    return min(a1,a2);
}
int query_max(int nodo, int l, int r, int a, int b){
    if(l>r || l>b || r<a)
        return 0;
    if(l>=a && r<=b)
        return tree[nodo].first;
    int mid=(l+r)/2;
    int a1=query_max(nodo*2,l,mid,a,b);
    int a2=query_max(nodo*2+1,mid+1,r,a,b);
    return max(a1,a2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,q;
    cin>>c>>q;
    for(int i=1;i<=c;i++){
        cin>>z[i];
    }
    build_tree(1,c,1);
    for(int i=0;i<q;i++){
        int r1,r2;
        cin>>r1>>r2;
        cout<<query_max(1,1,c,r1,r2)-query_min(1,1,c,r1,r2)<<"\n";
    }
    return 0;
}
