#include <bits/stdc++.h>
using namespace std;
char x[]={'W','T','Y','U','I','O','A','H','X','V','M'};
int main()
{
int g;
cin>>g;
for(int u=0;u<g;u++){
string s;
int sum=0,v=0;
cin>>s;
for(int a=0;a<s.size();a++){
   for(int b=10;b>=0;b--){
    if(s[a]==x[b])
        sum++;

}
}
if(sum==s.size())
    v++;
string h=s;
reverse(s.begin(),s.end());
if(h==s)
    v++;
    if(v==2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

    return 0;
}