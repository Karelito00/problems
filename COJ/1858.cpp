#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e4 + 2;

long long dp[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    long long m;
    cin>>n>>a>>b>>m;
    dp[0] = 1;
    for(int i = a; i <= b; i++){
        for(int j = i; j <= n; j++)
            dp[j] = (dp[j - i] + dp[j]) % m;
    }
    cout<<dp[n];
    return 0;
}
