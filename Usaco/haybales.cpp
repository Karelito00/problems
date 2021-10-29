#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;
int arr[MAXn];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    sort(arr + 1, arr + n + 1);
    while(q--){
        int a, b;
        cin>>a>>b;
        int aux = lower_bound(arr + 1, arr + n + 1, a) - arr;
        cout<<(upper_bound(arr + 1, arr + n + 1, b) - arr) - aux<<"\n";
    }
    return 0;
}
