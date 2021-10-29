#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 1;
long long mapa[101];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int sum = 0;
        long long sol = 0;
        mapa[0] = 1;
        for(int i = 0; i < n; i++){
            int h;
            cin>>h;
            h %= k;
            sum = (h + sum) % k;
            sol += mapa[sum]++;
        }
        cout<<sol<<"\n";
        fill(mapa, mapa + k, 0);
    }
    return 0;
}
