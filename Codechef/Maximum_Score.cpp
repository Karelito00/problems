#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 702;

long long arr[MAXn][MAXn];
int n;

long long funt(long long val){
    long long suma = val;
    for(int i = n - 2; i >= 0; i--){
        int pos = lower_bound(arr[i], arr[i] + n, val) - arr[i] - 1;
        if(pos == -1)
            return pos;
        suma += arr[i][pos];
        val = arr[i][pos];
    }
    return suma;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cin>>arr[i][j];
            sort(arr[i], arr[i] + n);
        }
        cout<<funt(arr[n - 1][n - 1])<<"\n";
    }
    return 0;
}
