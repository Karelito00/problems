#include <bits/stdc++.h>

using namespace std;
int z[]={3,5,6};
int table[115000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            table[i]=i;
        for(int u=0;u<3;u++){
            for(int y=z[u];y<=n;y++){
                table[y]=min(table[y-z[u]]+1,table[y]);
            }
        }
        cout<<"Case "<<b+1<<": "<<table[n]<<"\n";
    }
    return 0;
}
