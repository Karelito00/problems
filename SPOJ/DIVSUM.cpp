#include <bits/stdc++.h>

using namespace std;

int const MAXn = 5e5 + 2;

int con;
int criba[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 2; i <= MAXn - 2; i++){
        for(long long j = i * 2; j <= MAXn - 2; j += i)
            criba[j] += i;
    }
    criba[1] = -1;
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<criba[k] + 1<<"\n";
    }
    return 0;
}
