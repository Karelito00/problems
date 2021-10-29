#include <bits/stdc++.h>

using namespace std;
bool primo(int n){
if(n==2)
    return true;
if(n%2==0)
    return false;
for(int k=3;k*k<=n;k+=2)
    if(n%k==0)
    return false;
return true;
}
int z[500];
int main()
{
    int a,c=0;
    cin>>a;
    for(int g=2;g<=a;g++){
        if(primo(g)==1){
            z[c]=g;
            c++;
        }
    }
    int suma=0;
    for(int k=1;k<=a;k++){
            int o=0;
        for(int y=0;y<c;y++){
            if(k%z[y]==0)
                o++;
        }
    if(o==2)
        suma++;
    }
    cout<<suma;


    return 0;
}