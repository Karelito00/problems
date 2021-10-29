#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==90 && b==90 && c==90 && d==90)
        cout<<"none of the previous";
    else if(((a==90 && b==90 && c!=d) || (a==90 && c==90 && b!=d) || (a==90 && d==90 && b!=c) || (b==90 && c==90 && a!=d) || (b==90 && d==90 && a!=c) || (c==90 && d==90 && a!=b)) && a+b+c+d==360 )
        cout<<"right";
    else if(((a==b && c==d) || (a==c && b==d) || (a==d && b==c) || (b==c && a==d) || (b==d && a==c) || (c==d && a==b)) && a+b+c+d==360)
    cout<<"isosceles";
    else
        cout<<"none of the previous";


    return 0;
}