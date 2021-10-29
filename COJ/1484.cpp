#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,i;
   cin>>a;
   float y=-1;
   for(int b=0;b<a;b++){
    float m;
    cin>>m;
    if(m>=y){
    y=m;
    i=b;
}
   }
   cout<<i+1;


    return 0;
}
