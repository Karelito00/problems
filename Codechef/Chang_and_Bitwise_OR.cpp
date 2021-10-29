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
        int n;
        cin>>n;
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            sum |= x;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
