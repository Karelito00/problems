#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

long double arr[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        long double c, d, s;
        cin>>c>>d>>s;
        long double maxm = 0;
        for(int i = 1; i <= n; i++){
            maxm = mx(maxm, arr[i]);

        }
        cout<<fixed<<setprecision(9)<<maxm * (c - 1)<<"\n";
    }
    return 0;
}
