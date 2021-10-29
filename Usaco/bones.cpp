#include <bits/stdc++.h>

using namespace std;
map <int,int> mapa;
int main()
{
    freopen("bones.in","r",stdin);
    freopen("bones.out","w",stdout);
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    int suma=0;
    for(int k=1;k<=s1;k++){
        for(int i=1;i<=s2;i++){
            for(int j=1;j<=s3;j++){
                suma=k+i+j;
                mapa[suma]++;
            }
        }
    }
    map <int,int> ::iterator a1;
    int mayor=0,n=0;
    for(a1 = mapa.begin();a1 != mapa.end() ; a1++){
        if(a1->second>mayor){
            mayor=a1->second;
            n=a1->first;
        }
    }
    cout<<n;
    return 0;
}
