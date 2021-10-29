#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,sur=0;
    while(cin>>a){
     int suma=0;
     while(a>0){
        suma+=a%2;
        a=a/2;
     }
     if(suma%2==0)
        sur++;
    }
    cout<<sur;
    return 0;
}
