#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e6 + 2;
int pos[MAXn];
bool criba[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 2; i * i * i <= MAXn - 2; i++){
        int aux = i * i * i;
        for(int j = aux; j <= MAXn; j += aux)
            criba[j] = true;
    }
    int con = 0;
    for(int i = 1; i <= MAXn - 2; i++){
        if(!criba[i])
            pos[i] = ++con;
    }
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        int k;
        cin>>k;
        cout<<"Case "<<i<<": ";
        if(!pos[k])
            cout<<"Not Cube Free";
        else
            cout<<pos[k];
        cout<<"\n";
    }
    return 0;
}
