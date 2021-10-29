#include <iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int a=12;
float suma=0;
while (a>0){
    float b;
    cin>>b;
    suma+=b;
    a--;
}
cout<<"$"<<suma/12;
    return 0;
}