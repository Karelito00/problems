#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, x, k;
        cin>>n>>m>>x>>k;
        int even = 0, odd = 0;
        for(int i = 1; i <= k; i++){
            char z;
            cin>>z;
            if(z == 'E') even++;
            else odd++;
        }
        int sol = 0;
        for(int i = 1; i <= m; i++){
            if(i&1){
                sol += mn(x, odd);
                odd -= mn(x, odd);
            }
            else{
                sol += mn(x, even);
                even -= mn(x, even);
            }
        }
        cout<<(sol >= n ? "yes" : "no")<<"\n";
    }
    return 0;
}
