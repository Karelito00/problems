#include <bits/stdc++.h>

using namespace std;

bool dvi3(string n){
    int suma=0;
    for(int u=0;u<n.size();u++)
        suma+=(n[u]-'0');
    if(suma%3==0)
        return true;
    else
        return false;
}

bool dvi5(string n){
    if(n[(n.size())-1]=='0' || n[(n.size())-1]=='5')
        return true;
    else
        return false;
}

bool dvi11(string n){
    int sumai=0,sumap=0;
    for(int j=0;j<n.size();j++){
        if((j+1)%2==0)
            sumap+=(n[j]-'0');
        else
            sumai+=(n[j]-'0');
    }
    if(sumai-sumap==0 || (sumai-sumap)%11==0)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int a;
   cin>>a;
   for(int k=0;k<a;k++){
    string s;
    cin>>s;
    if(s.size()<=3){
            int o=s[0]-'0';
        for(int i=1;i<s.size();i++){
            o=(o*10)+(s[i]-'0');
        }
    if(o<495)
        cout<<"NO\n";
    else if(dvi11(s)==1 && dvi3(s)==1 && dvi5(s)==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    }
    else if(dvi11(s)==1 && dvi3(s)==1 && dvi5(s)==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
   }
    return 0;
}
