#include <bits/stdc++.h>

using namespace std;

int z[500];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int con = 0;
    for(int i=1;i<=500;i+=2){
        z[con] = i;
        con++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cout<<z[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
//Numbers Theory Fuerza Bruta
