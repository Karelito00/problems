#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    n*=2;
    int y=n%3;
    int o=(n-y)/3;
    if(y==1)
        cout<<1;
    else if(y==2)
        cout<<3;
    for(int u=0;u<o;u++)
        cout<<7;
    return 0;
}
