#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2;

int arr[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    sort(arr + 1, arr + n + 1);
    int maxm = 0;
    for(int i = 1; i <= n; i++){
        int pos = upper_bound(arr + 1, arr + n + 1, arr[i] + k) - arr - 1;
        maxm = mx(maxm, pos - i + 1);
    }
    cout<<maxm;
    return 0;
}
