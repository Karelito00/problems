#include <bits/stdc++.h>

using namespace std;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    while(scanf("%d",&a)!=EOF){
    int c=2;
    while(a!=1){
            int g=0;
            if(a%c==0){
            cout<<"(";
        while(a%c==0){
            if(a%c==0){
            g++;
            a=a/c;
        }
        }
        if(g!=0)
            cout<<c<<"("<<g<<")";

    cout<<")";
            }
            c++;
    }
    cout<<"\n";
    }
    return 0;
}
