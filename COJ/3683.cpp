#include <bits/stdc++.h>

using namespace std;

multiset < int > z;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    z.insert(0);
    z.insert(1000000);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int pos = *(z.lower_bound(k));
        int pos1 = *(--z.upper_bound(k));
        cout<<pos1<<" "<<pos<<"\n";
        z.insert(k);
    }
    return 0;
}

