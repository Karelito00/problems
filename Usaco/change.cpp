#include <bits/stdc++.h>

using namespace std;
int table[1001];
int z[11];
int main()
{
    freopen("change.in","r",stdin);
    freopen("change.out","w",stdout);
    int m,mon;
    cin>>m>>mon;
    for(int i=0;i<mon;i++){
        cin>>z[i];
    }
    sort(z,z+mon);
    for(int i=z[0];i<=m;i++){
        table[i]=i;
    }
    for(int i=1;i<mon;i++){
        for(int y=z[i];y<=m;y++){
            table[y]=min(table[y],table[y-z[i]]+1);
        }
    }
    cout<<table[m];
    return 0;
}
