#include <bits/stdc++.h>

using namespace std;
bool primo (int s){
if(s==2)
    return true;
if(s%2==0)
    return false;
for(int y=3;y*y<=s;y+=2){
    if(s%y==0)
    return false;
}
return true;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,n1;
        cin>>n>>n1;
       for(int x=n;x<=n1;x++){
        if(primo(x)==1)
            cout<<x<<"\n";
       }
       cout<<"\n";
    }
    return 0;
}