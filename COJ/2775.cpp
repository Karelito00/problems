#include <bits/stdc++.h>
using namespace std;
int main()
{
int a;
cin>>a;
for(int b=0;b<a;b++){
  string s;
  cin>>s;
if(s[0]=='a'  || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
    for(int y=0;y<s.size();y++){
        cout<<s[y];
    }
    cout<<"cow";
}
else{
    for(int x=1;x<s.size();x++){
        cout<<s[x];
    }
    cout<<s[0]<<"ow";
}
    cout<<endl;
}
    return 0;
}