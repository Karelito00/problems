#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long y,x;
        cin>>y>>x;
        long long u = y + x;
        cout<<((u*(u+1))/2)+1+y<<"\n";
    }
    return 0;
}
// Numbers Theory Formula de Sumatoria
