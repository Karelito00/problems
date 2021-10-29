#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int v,v1,n;
        cin>>v>>v1>>n;
        v+=v1;
        int soda=0;
        if(n!=1){
        while(v>=n){
            soda+=v/n;
            int h=v%n;
            v=(v/n)+h;
        }
        }
        cout<<soda<<"\n";
    }
    return 0;
}
