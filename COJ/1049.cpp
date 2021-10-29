#include <iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(0);
cin.tie(0);
   long long N,suma=0;
   cin>>N;
   if(N>0){
   for(int a=1;a<=N;a++){
    suma+=a;
   }
   }
   else if(N<0){
    for(int a=1;a>=N;a--){
        suma+=a;
    }
   }
   cout<<suma;
    return 0;
}