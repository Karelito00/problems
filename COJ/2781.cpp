#include <bits/stdc++.h>

using namespace std;
bool luz[501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l,m;
    cin>>l>>m;
    for(int j=0;j<m;j++){
        int n,a,b;
        cin>>n>>a>>b;
        a--;
        b--;
        if(n==0){
            for(int i=a;i<=b;i++){
                if(luz[i])
                    luz[i]=0;
                else
                    luz[i]=1;
            }
        }
        else{
            int con=0;
            for(int i=a;i<=b;i++)
                if(luz[i])
                con++;
            cout<<con<<"\n";
        }
    }
    return 0;
}
