#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long arr[16];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int u = 1; u <= t; u++){
        long long m;
        int n;
        cin>>m>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        long long sum = 0;
        for(int mask = 1; mask < (1<<n); mask++){
            long long mult = 1;
            for(int i = 0; i < n; i++){
                if(mask&(1<<i))
                    mult = (mult * arr[i]) / __gcd(mult, arr[i]);
                if(mult > m) break;
            }
            if(__builtin_popcount(mask)&1)
                sum += m / mult;
            else
                sum -= m / mult;
        }
        cout<<"Case "<<u<<": "<<m - sum<<"\n";
    }
    return 0;
}
