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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double l, r, x, y;
    double k;
    cin>>l>>r>>x>>y>>k;
    while(x < y){
        int mid = (x + y + 1) / 2;
        if(mid * k >= l && mid * k <= r){
            cout<<"YES";
            return 0;
        }
        if(mid * k > r)
            y = mid - 1;
        else
            x = mid + 1;

    }
    if(x == y && x * k >= l && x * k <= r)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
