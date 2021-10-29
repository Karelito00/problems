#include <bits/stdc++.h>

using namespace std;

int z[4];

int main()
{
    for(int i=0;i<3;i++){
        cin>>z[i];
    }
    sort(z,z+3);
    cout<<(z[1] - z[0]) + (z[2] - z[1]);
    return 0;
}
