#include <bits/stdc++.h>
bool primo(int n){
if(n==0)
    return false;
if(n==2)
    return true;
if(n%2==0)
    return false;
for(int h=3;h*h<=n;h+=2)
    if(n%h==0)
    return false;
return true;
}
using namespace std;
int z[5000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     int a,b,c=0;
    cin>>a>>b;
    while(a>0){
        int o;
        o=a%b;
        if(primo(o)==1){
        z[c]=o;
        c++;
        }
        a=a/b;
    }
    sort (z,z+c);
    cout<<c;
    for(int y=0;y<c;y++)
        cout<<" "<<z[y];
    return 0;
}
