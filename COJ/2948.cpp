#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int b;
    cin>>b;
    for(int i=0;i<b;i++){
   string a;
   cin>>a;
   int suma=0;
   for(int h=0;h<a.size();h++){
    suma+=a[h]-'0';
   }
   int c=0,k=suma;
   while(suma>0){
    int j;
    j=suma%10;
    suma=suma/10;
    c++;
   }
   while(c>1){
        int u=k;
        k=0;
        c=0;
    while(u>0){
        int o;
        o=u%10;
        k+=o;
        u=u/10;
        c++;
    }
    }
    cout<<k<<"\n";
    }
    return 0;
}
