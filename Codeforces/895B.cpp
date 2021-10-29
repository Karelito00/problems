#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 10;

int arr[MAXn];
vector < int > num;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, k;
    cin>>n>>x>>k;
    long long sol = 0;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        num.push_back(arr[i]/x);
    for(int i = 0; i < n; i++){
        int pos = lower_bound(arr, arr + n, arr[i]) - arr;
        int aux = upper_bound(num.begin() + pos, num.end(), ((arr[i] - 1) / x) + k) - num.begin();
        if(arr[i] % x == 0 && k == 1)
            sol++;
        else if(arr[i] % x && !k)
            sol++;
        aux--;
        if(num[aux] - ((arr[i] - 1) / x) != k)
            continue;
        pos = lower_bound(num.begin() + pos, num.end(), num[aux]) - num.begin();
        sol += aux - pos + 1;
        if(arr[pos] == arr[i]){
            if(arr[i] % x == 0 && k == 1)
            sol--;
        else if(arr[i] % x && !k)
            sol--;
        }
    }
    cout<<sol;
    return 0;
}
