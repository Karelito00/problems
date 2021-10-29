#include <bits/stdc++.h>
using namespace std;
int z[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
 int c=0;
 long long a;
 cin>>a;
 memset(z,0,sizeof z);
 if(a==0)
    break;
   while(a>0){
    int b;
    b=a%2;
    a=a/2;
    z[c]=b;
    c++;
   }
   int suma=0;
   cout<<"The parity of ";
   for(int y=c-1;y>=0;y--){
cout<<z[y];
if(z[y]==1){
    suma+=1;
}
   }
   cout<<" is "<<suma << " (mod 2).\n" ;




    }
    return 0;
}