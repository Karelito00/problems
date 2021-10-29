#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        int c = s.size();
        for(int i=0;i < c;i++){
          if(s[i]>='A'&& s[i]<='Z')
                s[i]=s[i]+32;
          else{
            s[i]=s[i]-32;
          }
        }
        cout<<s<<endl;
    }


    return 0;
}
