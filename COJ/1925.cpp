#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 5;

long long arr[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        long long h;
        cin>>h;
        while(h > 0){
            arr[i] = (arr[i] * 10) + (h % 10);
            h /= 10;
        }
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) cout<<arr[i]<<"\n";
    return 0;
}
