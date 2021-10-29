#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

const int MAXn = 2e5 + 10;

bool mex[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int y = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            mex[x] = true;
            y = mx(y, x);
        }
        int i = 0;
        for(; i <= y; i++){
            if(mex[i])
                continue;
            if(!k) break;
            k--;
        }
        cout<<i + k<<"\n";
        fill(mex, mex + y + 1, false);
    }
    return 0;
}
