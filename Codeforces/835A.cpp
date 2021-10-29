#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    if((s*v1) + (2*t1) < (s*v2) + (2*t2))
        cout<<"First";
    else if((s*v1) + (2*t1) > (s*v2) + (2*t2))
        cout<<"Second";
    else
        cout<<"Friendship";
    return 0;
}
