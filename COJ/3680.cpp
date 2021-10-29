#include <bits/stdc++.h>

using namespace std;

long long table[100001];

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
        long long w;
        cin>>w;
        for(int i=1;i<=n;i++){
            cin>>table[i];
        }
        sort(table+1,table+n+1);
        for(int i=2;i<=n;i++){
            table[i] += table[i-1];
        }
        cout<<upper_bound(table+1,table+n+1,w) - table - 1<<"\n";
    }
    return 0;
}
