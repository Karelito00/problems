#include <bits/stdc++.h>

using namespace std;
int abc[27];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            abc[s[j]-'A']++;
        }
        bool flag=false;
        if(abc['B'-'A']!=abc['R'-'A']){
            flag=true;
        }
        else if(abc['R'-'A']!=abc['O'-'A']){
            flag=true;
        }
        else if(abc['O'-'A']!=abc['K'-'A']){
            flag=true;
        }
        else if(abc['K'-'A']!=abc['E'-'A']){
            flag=true;
        }
        else if(abc['E'-'A']!=abc['N'-'A']){
            flag=true;
        }
        if(flag==true)
            cout<<"Secure\n";
        else
            cout<<"No Secure\n";
        memset(abc,0,sizeof abc);
    }
    return 0;
}
