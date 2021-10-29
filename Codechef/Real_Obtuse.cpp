#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long k, a, b;
        cin>>k>>a>>b;
        if(a > b)
            swap(a,b);
        if(b - a - 1 == k - (b - a) - 1){
            cout<<0<<"\n";
            continue;
        }
        cout<<mn(b - a - 1, k - (b - a) - 1)<<"\n";
    }
    return 0;
}
