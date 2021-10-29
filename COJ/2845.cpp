#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    while(cin>>a && cin>>b){
        if(a=="0" && b=="0"){
            cout<<"AXIS";
            break;
        }
        if(a=="0" || b=="0"){
            cout<<"AXIS\n";
        }
        else if(a[0]!='-' && b[0]!='-')
            cout<<"Q1\n";
        else if(a[0]=='-' && b[0]!='-')
            cout<<"Q2\n";
        else if(a[0]!='-' && b[0]=='-')
            cout<<"Q4\n";
        else if(a[0]=='-' && b[0]=='-')
            cout<<"Q3\n";
    }
    return 0;
}
