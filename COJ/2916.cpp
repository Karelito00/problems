#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        if(__gcd(n,m)!=1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}