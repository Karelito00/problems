#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long arr[21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long k;
    int n;
    cin>>k>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int sol = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        long long mult = 1;
        int con = 0;
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)){
                mult = (arr[i] * mult)/ __gcd(arr[i], mult);
                con++;
            }
            if(mult > k)
                break;
        }
        if(con&1) sol += k / mult;
        else sol -= k / mult;
    }
    cout<<sol;
    return 0;
}
