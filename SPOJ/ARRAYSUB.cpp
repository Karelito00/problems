#include <bits/stdc++.h>
#define mx(a, b) (a > b ? a : b)

using namespace std;

int const MAXn = 1e5 + 2, loga = log2(MAXn) + 2;

int RMQ[MAXn][loga];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>RMQ[i][0];
    for(int e = 1; (1<<e) <= n; e++){
        for(int i = 1; i + (1<<e) <= n + 1; i++)
            RMQ[i][e] = mx(RMQ[i][e - 1], RMQ[i + (1<<(e - 1))][e - 1]);
    }
    int k;
    cin>>k;
    int lg = log2(k);
    for(int i = 1, j = k; j <= n; j++, i++){
        cout<<mx(RMQ[i][lg], RMQ[j - (1<<lg) + 1][lg])<<" ";
    }
    return 0;
}
