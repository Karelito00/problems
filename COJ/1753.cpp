#include <bits/stdc++.h>

using namespace std;
char x[]={'A','a','B','b','c','C','D','E','e','d','f','F','g','G','H','h','i','I','J','j','k','K','L','l','m','M','n','N','O','o','p','P','Q','q','R','r','S','s','T','t','U','u','v','V','W','w','X','x','Y','y','Z','z'};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        for(int y=0;y<s.size();y++){
         for(int ca=0;ca<=51;ca++){
            if(s[y]==x[ca] && ca<=5)
                s[y]='2';
            else if(s[y]==x[ca] && ca<=11 )
                s[y]='3';
            else if(s[y]==x[ca] && ca<=17)
                s[y]='4';
            else if(s[y]==x[ca] && ca<=23)
                s[y]='5';
            else if(s[y]==x[ca] && ca<=29)
                s[y]='6';
            else if(s[y]==x[ca] && ca<=37)
                s[y]='7';
            else if(s[y]==x[ca] && ca<=43)
                s[y]='8';
            else if(s[y]==x[ca] && ca<=51)
                s[y]='9';
         }
    }
    string h=s;
    reverse(s.begin(),s.end());
    if(s==h)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    }
    return 0;
}
