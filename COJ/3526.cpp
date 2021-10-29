#include <bits/stdc++.h>

using namespace std;

int z[100001];
int abi[100001];
int n,maxm;
void update(int pos){
    while(pos<=maxm){
        abi[pos]++;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int con=0;
    while(pos>=1){
        con+=abi[pos];
        pos-=(pos&-pos);
    }
    return con;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        z[i]=x;
        maxm=max(maxm,x);
    }
    for(int u=n;u>=1;u--){
        int m=z[u];
        z[u]=n-u-query(m);
        update(m);
    }
    for(int u=1;u<=n;u++){
        cout<<z[u]<<" ";
    }
    return 0;
}
