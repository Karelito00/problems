#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  while(1){
    string b;
    cin>>b;

if(b[0]=='0'){
        break;
}
  int sumap=0,sumai=0,r;
  for(int c=0;c<b.length();c+=2){
    sumap+=b[c]-'0';
  }
  for(int h=1;h<b.length();h+=2){
    sumai+=b[h]-'0';
  }
  r=sumap-sumai;
  if(r%11==0)
    cout<<b<<" is a multiple of 11.\n";
    else
    cout<<b<<" is not a multiple of 11.\n";
  }
    return 0;
}