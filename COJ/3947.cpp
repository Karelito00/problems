#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unsigned long long arr[12];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long k;
    cin>>k;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    unsigned long long sol = 0;
    for(int mask = 1; mask < (1<<n); mask++){
        unsigned long long mult = 1;
        for(int i = 0; i < n; i++){
            if(mask&(1<<i))
                mult = (arr[i] * mult)/__gcd(arr[i], mult);
            if(mult > k) break;
        }
        if(__builtin_popcount(mask)&1)
            sol += k / mult;
        else
            sol -= k / mult;
    }
    cout<<sol;
    return 0;
}
