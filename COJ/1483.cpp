#include <bits/stdc++.h>
using namespace std;
int main()
{
   string a;
   cin>>a;
   if(a=="rectangle"){
    int b,c;
    cin>>b>>c;
    cout<<b*c;
   }
   else if(a=="square"){
    int h;
    cin>>h;
    cout<<h*h;
   }
    return 0;
}