#include <bits/stdc++.h>

using namespace std;
int z[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a;
        cin>>a;
        int m=a;
        if(a==-1)
            break;
            int c=0;
    for(int x=1;x<=a/2;x++){
       if(a%x==0){
            z[c]=x;
       c++;
       }
    }
    for(int k=0;k<c;k++){
        a-=z[k];
    }
    if(a==0){
        cout<<m<<" = ";
        for(int k=0;k<c;k++)
            if(k!=c-1)
            cout<<z[k]<<" + ";
            else
                cout<<z[k];
              }
    else
        cout<<m<<" is NOT perfect.";
    cout<<"\n";
        }

    return 0;
}
