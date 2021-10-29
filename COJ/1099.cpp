#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a,e,r;
        cin>>a;
        if(a==0)
            break;
        cin>>e>>r;

        if(a==0)
            break;
        if(a>e && a>r){
            if(a*a==(e*e)+(r*r)){
                cout<<"right\n";
    }
        else{
                cout<<"wrong\n";
                            }
        }
        if(e>a && e>r){
            if(e*e==(a*a)+(r*r)){
                cout<<"right\n";
    }
        else{
                cout<<"wrong\n";
                            }
        }
        if(r>e && r>a){
            if(r*r==(e*e)+(a*a)){
                cout<<"right\n";
    }
        else{
                cout<<"wrong\n";
                            }
        }
    }
    return 0;
}