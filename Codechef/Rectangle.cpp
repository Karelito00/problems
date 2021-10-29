#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int arr[4];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i = 0; i < 4; i++)
            cin>>arr[i];
        sort(arr, arr + 4);
        if(arr[1] == arr[0] && arr[2] == arr[3])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
