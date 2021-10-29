#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,b;
    cin>>a>>b;
    if(a > b)
        swap(a,b);
    long long n = a;
    for(int i=1;i<n;i++)
        a *= i;
    cout<<a;
    return 0;
}
