#include <bits/stdc++.h>

using namespace std;
bool cell[150];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
    int a;
    cin>>a;
    memset(cell, true ,sizeof cell);
    for(int i=2;i<=a;i++){
        for(int u=i;u<=a;u+=i){
            if(cell[u])
                cell[u]=false;
            else
                cell[u]=true;
        }
    }
    int suma=0;
    for(int j=1;j<=a;j++){
        if(cell[j])
            suma++;
    }
    cout<<suma<<"\n";
    }
    return 0;
}
