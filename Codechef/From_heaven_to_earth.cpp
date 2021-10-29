#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        double n, v1, v2;
        cin>>n>>v1>>v2;
        double elev = n * 2;
        double stairs = sqrt(2) * n;
        cout<<(v1 / stairs > v2 / elev ? "Stairs" : "Elevator");
        cout<<"\n";
    }
    return 0;
}
