#include <bits/stdc++.h>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int a=0,e=0,i=0,o=0,u=0;
    string s;
    while(cin>>s){
        for(int p=0;p<s.size();p++){
            if(s[p]=='a' || s[p]=='A')
                a++;
            if(s[p]=='e' || s[p]=='E')
                e++;
            if(s[p]=='i' || s[p]=='I')
                i++;
            if(s[p]=='o' || s[p]=='O')
                o++;
            if(s[p]=='u' || s[p]=='U')
                u++;
        }
    }
    cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u;
    return 0;
}
