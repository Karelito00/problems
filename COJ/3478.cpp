#include <bits/stdc++.h>

using namespace std;
int z[1000000];
int main()
{
    string s;
    cin>>s;
    int u=s.size();
    if(u%3==0){
    int i=3,x=0;
    for(int l=0;l<s.size();l+=3){
        int suma=0,c=2;
        for(int j=l;j<i;j++){
            suma+=(s[j]-'0')*pow(2,c);
            c--;
        }
        i+=3;
        z[x]=suma;
        x++;
    }
    for(int h=0;h<x;h++)
        cout<<z[h];
    }
    if(u%3==1){
    int i=4,x=0;
    for(int l=1;l<s.size();l+=3){
        int suma=0,c=2;
        for(int j=l;j<i;j++){
            suma+=(s[j]-'0')*pow(2,c);
            c--;
        }
        i+=3;
        z[x]=suma;
        x++;
    }
    cout<<(s[0]-'0')*1;
    for(int h=0;h<x;h++)
        cout<<z[h];
    }
    if(u%3==2){
    int i=5,x=0;
    for(int l=2;l<s.size();l+=3){
        int suma=0,c=2;
        for(int j=l;j<i;j++){
            suma+=(s[j]-'0')*pow(2,c);
            c--;
        }
        i+=3;
        z[x]=suma;
        x++;
    }
    int c=1,suma=0;
    for(int d=0;d<=1;d++){
            suma+=(s[d]-'0')*pow(2,c);
            c--;
        }
        cout<<suma;
    for(int h=0;h<x;h++)
        cout<<z[h];
    }
    return 0;
}
