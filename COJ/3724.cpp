#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s[s.size()-2]=='P'){
        int u=(s[0]-'0')*10+(s[1]-'0');
        if(u!=12){
            u+=12;
            cout<<u;
            for(int j=2;j<s.size()-2;j++)
                cout<<s[j];
        }
        else if(u==12){
            for(int j=0;j<s.size()-2;j++)
                cout<<s[j];
        }
    }else if(s[s.size()-2]=='A'){
        int u=(s[0]-'0')*10+(s[1]-'0');
        if(u==12){
            cout<<"00";
            for(int y=2;y<s.size()-2;y++)
                cout<<s[y];
        }
        else if(u!=12){
            for(int p=0;p<s.size()-2;p++)
                cout<<s[p];
        }
    }
    return 0;
}
