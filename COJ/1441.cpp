#include <iostream>

using namespace std;

int main()
{
   while(1){
    int a,b,c,d,e,r;
    cin>>a>>b>>c;
    if(a==0 && b==0 && c==0)
        break;
    d=(a*a)+(b*b);
    e=(c*c)+(b*b);
    r=(a*a)+(c*c);
    if(d==(c*c) || e==(a*a) || r==(b*b))
        cout<<"right \n";
    else
        cout<<"wrong \n";

   }
    return 0;
}