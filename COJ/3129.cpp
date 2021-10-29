#include <bits/stdc++.h>

using namespace std;
int z[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int c,k;
        string s;
        cin>>c>>s>>k;
        int l=0;
        if(s=="odd"){
    for(int u=1;u<=c;u++){
        if(u%2==0){
            z[l]=u;
        l++;
        }
    }
        }
        if(s=="even"){
    for(int u=1;u<=c;u++){
        if(u%2!=0){
            z[l]=u;
        l++;
        }
    }
        }
        cout<<z[k-1]<<"\n";
    }

    return 0;
}
