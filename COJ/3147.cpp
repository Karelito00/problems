#include <bits/stdc++.h>

using namespace std;
int table[52];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag=false;
        for(int y=1;y<=n;y++){
            cin>>table[y];
            table[y]+=table[y-1];
        }
        for(int y=1;y<=n;y++){
            for(int x=0;x<y;x++){
                if(table[y]-table[x]==0){
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
