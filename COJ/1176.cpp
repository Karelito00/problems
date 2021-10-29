#include <bits/stdc++.h>

using namespace std;
int z[50];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     while(1){
        int a;
        cin>>a;
        if(a<0)
            break;
            int c=0;
        while(a>0){
            z[c]=a%3;
            a=a/3;
            c++;
        }
        for(int u=c-1;u>=0;u--){
            cout<<z[u];
        }
        cout<<"\n";
     }

    return 0;
}
