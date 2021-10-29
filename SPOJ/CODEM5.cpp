#include <bits/stdc++.h>
#define mn(a, b) (a < b ? a : b)

using namespace std;

int arr[21];

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
        for(int i = 0; i < n; i++) cin>>arr[i];
        int minm = 24;
        for(int mask = 1; mask < (1<<n); mask++){
            int sum = 0;
            int con = 0;
            for(int i = 0; i < n; i++){
                if(mask&(1<<i)){
                    sum += arr[i];
                    con++;
                }
            }
            if(sum == k) minm = mn(con, minm);
        }
        if(minm != 24)
            cout<<minm<<"\n";
        else
            cout<<"impossible\n";
    }
    return 0;
}
