#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int y;
    cin>>y;
    for(int k=0;k<y;k++){
   int a;
   cin>>a;
   int suma=1,t=4;
   for(int y=1;y<a;y++){
    suma+=t;
    t+=4;
   }
   cout<<suma<<"\n";
    }
    return 0;
}
