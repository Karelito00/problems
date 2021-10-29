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
    /*freopen(".in","r",stdin);
    freopen(".out","w",stdout);*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int valt = n - 92682;
        cout<<92682 - (55608 + valt + 1)<<" ";
        for(int i = 92681; i >= 1; i--)
            cout<<i<<" ";
        for(int i = 0; i < valt; i++)
            cout<<1<<" ";
        cout<<"\n";
    }
    return 0;
}
