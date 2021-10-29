#include <bits/stdc++.h>
using namespace std;
int z[10001];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int a;
cin>>a;
for(int c=0;c<a;c++){
cin>>z[c];
}
int f;
for(int x=0;x<a-1;x++){
    for(int j=x+1;j<a;j++){
        if(z[x]>z[j]){
         f=z[x];
         z[x]=z[j];
         z[j]=f;
}
}
}
for(int h=0;h<a;h++){
    cout<<z[h]<<"\n";
}
return 0;
}