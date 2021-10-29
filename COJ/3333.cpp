#include <bits/stdc++.h>

using namespace std;
int z[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int a;
   cin>>a;
   int suma=0;
   for(int b=0;b<a;b++){
    int g;
    cin>>g;
    suma+=g;
    z[b]=suma;
   }
   int x;
   cin>>x;
   for(int h=0;h<x;h++){
   int l,m;
   cin>>l>>m;
   cout<<z[m-1]-z[l-2]<<"\n";
   }
    return 0;
}
