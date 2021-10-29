#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, mi=0, ma=0;
    cin>>n;
    string g;
    cin>>g;
    for (int i =0; i< n; i++){
        if (g[i] >= 'a' && g[i] <= 'z')
            mi++;
        else if (g[i] >= 'A' && g[i] <= 'Z')
            ma++;
    }
    cout<<ma<<" "<<mi;
    return 0;
}
