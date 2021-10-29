#include <bits/stdc++.h>

using namespace std;
int table[501];
int main()
{
    freopen("hayexp.in","r",stdin);
    freopen("hayexp.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,q;
    cin>>a>>q;
    for(int i=1;i<=a;i++){
        cin>>table[i];
        table[i]+=table[i-1];
    }
    for(int u=0;u<q;u++){
        int n,n1;
        cin>>n>>n1;
        cout<<table[n1]-table[n-1]<<"\n";
    }
    return 0;
}
