#include <bits/stdc++.h>

using namespace std;
int a;
int main()
{
    while(cin>>a){
    int mayorn=0,mayore=0,arg=0;
     if(a==0)
break;
    for(int i=0;i<a;i++){
        int n,e;
        cin>>n>>e;
        int t=e*log10(n);
        if(t>arg){
            arg=t;
            mayorn=n;
            mayore=e;
        }
    }
    cout<<mayorn<<" "<<mayore<<"\n";
}
    return 0;
}