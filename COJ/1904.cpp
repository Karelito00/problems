#include <bits/stdc++.h>

using namespace std;
int n;
long long mat[4001][4001];
void update(int r,int c,int val){
    for(int i=r;i<=n;i+=(i&-i)){
        for(int j=c;j<=n;j+=(j&-j)){
            mat[i][j]=(mat[i][j]+val)%10000;
        }
    }
}
int query(int y,int x){
    long long suma=0;
    for(int i=y;i>=1;i-=(i&-i)){
        for(int j=x;j>=1;j-=(j&-j)){
            suma=(suma+mat[i][j])%10000;
        }
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u,q;
    cin>>n>>u>>q;
    for(int y=0;y<u+q;y++){
        int q,r,c,k;
        cin>>q>>r>>c>>k;
        if(q==1){
            update(r,c,k*5);
            if(r-1>=1){
                update(r-1,c,k*3);
                if(c+1<=n)
                    update(r-1,c+1,k*2);
                if(c-1>=1)
                    update(r-1,c-1,k*2);
            }
            if(r+1<=n){
                update(r+1,c,k*3);
                if(c+1<=n)
                    update(r+1,c+1,k*2);
                if(c-1>=1)
                    update(r+1,c-1,k*2);
            }
            if(c+1<=n)
                    update(r,c+1,k*3);
            if(c-1>=1)
                    update(r,c-1,k*3);
        }
        else{
            int in;
            cin>>in;
            int m=r,p=c,M=k,P=in;
            cout<<(query(M,P)+query(m-1,p-1)-query(M,p-1)-query(m-1,P)+20000)%10000<<"\n";
        }
    }
    return 0;
}
