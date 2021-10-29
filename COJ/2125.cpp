#include <bits/stdc++.h>

using namespace std;

pair <int,int> z[100001];
int tree[400001];

void build_tree(int nodo,int l,int r){
    if(l==r){
        tree[nodo]=z[l].first;
        z[l].second=nodo;
        return;
    }
    int mid=(l+r)/2;
    build_tree(nodo*2,l,mid);
    build_tree(nodo*2+1,mid+1,r);
    tree[nodo]=tree[nodo*2]*tree[nodo*2+1];
}

int query(int nodo,int l,int r,int a,int b){
    if(l>r || l>b || r<a)
        return 1;
    if(l>=a && r<=b)
        return tree[nodo];
    int mid=(l+r)/2;
    int a1=query(nodo*2,l,mid,a,b);
    int a2=query(nodo*2+1,mid+1,r,a,b);
    return a1*a2;
}

void update(int nodo){
    nodo/=2;
    while(nodo>=1){
        tree[nodo]=tree[nodo*2]*tree[nodo*2+1];
        nodo/=2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    while(cin>>n>>q){
        for(int k=1;k<=n;k++){
            cin>>z[k].first;
            if(z[k].first>0)
                z[k].first=1;
            else if(z[k].first<0)
                z[k].first=-1;
        }
        build_tree(1,1,n);
        for(int o=0;o<q;o++){
            char h;
            int g,p;
            cin>>h>>g>>p;
            if(h=='P'){
                int kk=query(1,1,n,g,p);
                if(kk>0)
                    cout<<'+';
                else if(kk<0)
                    cout<<'-';
                else
                    cout<<'0';
            }
            else{
                if(p>0)
                    p=1;
                else if(p<0)
                    p=-1;
                tree[z[g].second]=p;
                update(z[g].second);
            }
        }
        cout<<"\n";
    }
    return 0;
}
