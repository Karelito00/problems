#include <bits/stdc++.h>

using namespace std;
int z[1001];
int camb[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    while(cin>>a){
        for(int i=1;i<=a;i++){
            cin>>z[i];
        }
        for(int k=1;k<=a;k++){
            if(k!=z[k]){
                int u=z[k];
                int h=z[u];
                z[k]=h;
                z[u]=u;
                camb[k]++;
                camb[u]++;
            }
        }
        int best=0;
        for(int i=1;i<=a;i++){
            best=max(best,camb[i]);
        }
        cout<<best<<"\n";
        memset(camb,0,sizeof camb);
    }
    return 0;
}
