#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   while(1){
    int a;
    cin>>a;
    if(a==0)
        break;
        long long suma=0;
    for(int i=1;i<=a;i++)
        suma+=i*i;
   cout<<suma<<"\n";
   }
    return 0;
}
