#include <bits/stdc++.h>

using namespace std;
int z[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int j,k,c=0;
        cin>>j>>k;
        int t=j*k;
        if(j<=k){
        for(int n=1;n<=j;n++){
            if(j%n==0 && k%n==0){
                z[c]=n;
                c++;
            }
        }
        }
        else if(j>k){
        for(int n=1;n<=k;n++){
            if(j%n==0 && k%n==0){
                z[c]=n;
                c++;
            }
        }
        }
        int l=0;
        for(int o=c-1;o>=0;o--){
         if(t%(z[o]*z[o])==0){
            l=t/(z[o]*z[o]);
            break;
         }
        }
        cout<<l<<"\n";
    }
    return 0;
}
