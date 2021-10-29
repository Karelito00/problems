#include <bits/stdc++.h>

using namespace std;

long long funt(long long n,long long b){
    if(b >= n)
        return 0;
    if(b % 2 == 0 && b >= n/2)
        return n - b;
    if(b % 2 != 0 && b > n/2)
        return n - b;
    long long div = n / b;
    if(div % 2 != 0)
        div++;
    div /= 2;
    return (n - (b * div)) * ((b * div) / b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n,b;
        cin>>n>>b;
        cout<<funt(n,b)<<"\n";
    }
    return 0;
}
