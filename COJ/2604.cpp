#include <bits/stdc++.h>

using namespace std;
int n[10];
char l[10];
int main()
{
    int a;
    cin>>a;
    int u=0;
    for(int i=0;i<=a;i++){
        string s;
        cin>>s;
        if(i!=a){
        cin>>l[u];
        u++;
        }
       int suma=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='.')
                suma+=1;
            else if(s[j]==':')
                suma+=2;
            else if(s[j]=='-')
                suma+=5;
            else if(s[j]=='=')
                suma+=10;
        }
        n[i]=suma;
    }
    int ka=0;
    for(int o=0;o<a;o++){
        int mul=0;
        if(ka==1){
            o=0;
        ka=0;
        }
        if(l[o]=='*'){
            mul=n[o]*n[o+1];
        n[o]=mul;
        for(int h=o+1;h<=a;h++){
            n[h]=n[h+1];
        }
        for(int h=o;h<a;h++){
            l[h]=l[h+1];
        }
        ka=1;
        }
    }
    int suma1=0;
    for(int p=0;p<=a;p++)
        suma1+=n[p];
        cout<<suma1;
    return 0;
}

