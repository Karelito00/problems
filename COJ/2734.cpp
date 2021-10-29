#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    string s;
    long long suma=0;
    while(cin>>s && cin>>a){
        if(s=="suma")
            suma+=a;
        else if(s=="resta")
            suma-=a;
    }
    cout<<"resultado: "<<suma;
    return 0;
}
