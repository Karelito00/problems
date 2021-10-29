#include <bits/stdc++.h>

using namespace std;
int z[]={5,10,25,50};
long long table[7491];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    table[0]=1;
    for(int u=1;u<=7490;u++)
        table[u]=1;
    for(int i=0;i<4;i++){
        for(int u=z[i];u<=7490;u++){
            table[u]+=table[u-z[i]];
        }
    }
    int a;
    while(cin>>a){
    cout<<table[a]<<"\n";
    }
    return 0;
}
