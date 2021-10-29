#include <bits/stdc++.h>

using namespace std;
int z[1000000];
int x[1000000];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);   
 long a,b,f=0,g=0;
    cin>>a>>b;
    while(a>0){
        int c;
        c=a%10;
        a=a/10;
        z[f]=c;
        f++;
        }
    while(b>0){
        int d;
        d=b%10;
        b=b/10;
        x[g]=d;
        g++;
    }
    long suma=0,r;
    for(int h=f-1;h>=0;h--){
for(int k=g-1;k>=0;k--){
    r=z[h]*x[k];
    suma+=r;
}
   }
cout<<suma;
    return 0;
}