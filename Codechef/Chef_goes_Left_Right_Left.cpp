#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn  = 1e6 + 10;

int arr[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, l;
        cin>>n>>l;
        set < int > num;
        bool sol = false;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(i > 1){
                int a = arr[i - 1], b = arr[i];
                int np = *num.upper_bound(a);
                if(np != *num.upper_bound(b))
                    sol = true;
            }
            if(i >= 1)
                num.insert(arr[i - 1]);
        }
        cout<<(sol ? "NO" : "YES")<<"\n";
    }
    return 0;
}
