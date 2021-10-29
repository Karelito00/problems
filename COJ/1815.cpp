#include <bits/stdc++.h>

using namespace std;
int z[21];
bool flag[20000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>z[i];
    }
    for(int y=1;y<(1<<a);y++){
        int suma=0;
        for(int u=0;u<a;u++){
            if(y&(1<<u))
                suma+=z[u];
        }
        flag[suma]=true;
    }
    int q;
    cin>>q;
    for(int j=0;j<q;j++){
        int que;
        cin>>que;
        if(flag[que])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
