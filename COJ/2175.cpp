#include <bits/stdc++.h>

using namespace std;
int z[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c=0;
    for(int b=2;b<=1000000;b++){
      z[c]=b;
      c++;
    }
    int n=0,k=2;
    while(n<(1000000/2)-2){
        for(int b=n;b<=1000000;b+=k){
            if(b!=n && z[b]!=-1)
                z[b]=-1;
        }
        k++;
        n++;
    }
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int g;
        cin>>g;
        int o=g-2,l=g-2;
        int menorp,mayorp;
        while(1){
            if(z[o]!=-1){
                menorp=z[o];
                break;
            }
            o--;
        }
        while(1){
            if(z[l]!=-1){
                mayorp=z[l];
                break;
            }
            l++;
        }
        cout<<menorp<<" "<<mayorp<<"\n";
        }

    return 0;
}
