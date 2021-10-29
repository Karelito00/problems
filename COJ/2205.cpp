#include <bits/stdc++.h>

using namespace std;

int cant1(int l,int k){
    int suma=0;
    for(int y=l;y<=k;y++){
        int h=y;
        while(h>0){
            if(h%2==1)
            suma++;
            h=h/2;
        }
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int d,f;
        cin>>d>>f;
        cout<<cant1(d,f)<<"\n";
    }
    return 0;
}
