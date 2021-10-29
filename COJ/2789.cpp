#include <bits/stdc++.h>

using namespace std;
int z[1010];
int main()
{
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]!='+')
        z[i]=a[i];
    }
    sort(z,z+a.size());
    for(int b=0;b<a.size();b++){
     if(b<a.size()-1){
     if(z[b]!=0)
    cout<<z[b]-48<<"+";
     }
     else
        cout<<z[b]-48;

         }
    return 0;
}