#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int arr[] = {2, 3, 5};

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int sol = 0;
    for(int mask = 1; mask < (1<<3); mask++){
        int mult = 1;
        for(int i = 0; i < 3; i++){
            if(mask&(1<<i))
                mult *= arr[i];
        }
        if(__builtin_popcount(mask)&1)
            sol += n / mult;
        else
            sol -= n / mult;
    }
    cout<<n - sol<<"\n";
    return 0;
}
