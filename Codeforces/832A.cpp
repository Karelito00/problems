#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    cin>>n>>k;
    if((n / k) % 2 == 0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}