#include <bits/stdc++.h>

using namespace std;
int z[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        cin>>z[b];

    }
    sort(z,z+a);
    for(int h=0;h<a;h++){
        cout<<z[h]<<"\n";
    }
    return 0;
}
