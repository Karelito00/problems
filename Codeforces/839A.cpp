#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    int pos = -1;
    int dulces = 0;
    for(int i = 1; i <= n; i++){
        int n1;
        cin>>n1;
        dulces += n1;
        k -= min(8,dulces);
        dulces -= min(dulces, 8);
        if(k <= 0 && pos == -1)
            pos = i;
    }
    cout<<pos;
    return 0;
}
