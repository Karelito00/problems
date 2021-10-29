#include <bits/stdc++.h>

using namespace std;
int z[100];
int main()
{
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        cin>>z[b];
    }
    int pj1=0,pj2=0;
    for(int y=0;y<a;y++){
        if(a-y<=1)
            break;
        if(y%2==0)
            pj1+=z[y+1]+z[y];
        else
            pj2+=z[y+1]+z[y];
        z[y+1]+=z[y];
    }
    if(pj1>pj2)
        cout<<"First";
    else if(pj1<pj2)
        cout<<"Second";
    else if(pj1==pj2)
        cout<<"Tie";
    return 0;
}
