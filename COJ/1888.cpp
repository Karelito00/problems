#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool six_present(string t){
    for(int y=0;y<t.size();y++){
        if(t[y]=='6')
            return true;
    }
    return false;
}

bool six_div(string t){
    ll con=0;
    ll suma=0;
    if(t[0]=='-'){
       for(int u=1;u<t.size();u++){
        suma+=(t[u]-'0');
    }
    if(suma%3==0)
        con++;
    if((t[t.size()-1]-'0')%2==0)
        con++;
    }
    else{
    for(int u=0;u<t.size();u++){
        suma+=(t[u]-'0');
    }
    if(suma%3==0)
        con++;
    if((t[t.size()-1]-'0')%2==0)
        con++;
    }
    if(con==2)
        return true;
    else
        return false;
}

bool suma_digit(string t){
    ll suma=0,con=0;
    if(t[0]=='-'){
    for(int u=1;u<t.size();u++){
        suma+=(t[u]-'0');
    }
    }else{
        for(int u=0;u<t.size();u++){
        suma+=(t[u]-'0');
    }
    }
    ll suma2=0;
    ll x=suma%10;
    while(suma>0){
        suma2+=suma%10;
        suma/=10;
    }
    if(suma2%3==0)
        con++;
    if(x%2==0)
        con++;
    if(con==2)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        int c=0;
        if(s=="0")
            break;
        if(six_present(s))
            c++;
        if(six_div(s))
            c++;
        if(suma_digit(s))
            c++;
        if(c==3)
            cout<<"EVIL\n";
        else
            cout<<"GOOD\n";
    }
    return 0;
}
