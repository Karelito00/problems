#include <bits/stdc++.h>
typedef long long ll;
ll z[10000];
ll j[10000];
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int a;
   cin>>a;
   for(int b=0;b<a;b++){
    int n,r;
    cin>>n>>r;
    z[b]=n;
    j[b]=r;
    }
    int h=0,f;
    for(int y=0;y<a;y++){
        for(int u=y+1;u<a;u++){
            if(z[y]>z[u]){
                h=z[u];
                f=j[u];
                z[u]=z[y];
                j[u]=j[y];
                z[y]=h;
                j[y]=f;
            }
        }
    }
    for(int h=0;h<a;h++){
            if(z[h]!=0 &&j[h]!=1){
            ll s=0;
            int l;
            for(int k=0;k<a;k++){
                if(z[h]==z[k]){
                    s+=j[k];
                    j[k]=1;
                    l=z[k];
                }

            }
        cout<<l<<" "<<s<<endl;
        z[h]=0;
        }
    }



    return 0;
}