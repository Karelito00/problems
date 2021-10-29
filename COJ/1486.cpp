#include <bits/stdc++.h>

using namespace std;
int z[10];
long long pascal[30][30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pascal[0][0]=1;
    for(int u=1;u<=26;u++){
        for(int y=0;y<=u;y++){
            pascal[u][y]=pascal[u-1][y]+pascal[u-1][y-1];
        }
    }
    int t;
    cin>>t;
    for(int b=0;b<t;b++){
        int suma=0;
        for(int i=0;i<9;i++){
            cin>>z[i];
            suma+=z[i];
        }
        unsigned long long h=1;
        for(int k=0;k<9;k++){
            if(z[k]!=0){
                h*=pascal[suma][z[k]];
                suma-=z[k];
            }
        }
        cout<<h<<"\n";
    }
    return 0;
}
