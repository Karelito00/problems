#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 10, TB = sqrt(MAXn) + 10;
vector < int > B[TB];
int arr[MAXn];

int query(int a, int b){
    int sol = 0;
    a--, b--;
    int mxm = mx(arr[a], arr[b]);
    int BA = a/TB;
    for(; a/TB == BA && a <= b; a++)
        if(arr[a] > mxm) sol++;
    int BB = b/TB;
    for(; b/TB == BB && b >= a; b--)
        if(arr[b] > mxm) sol++;
    for(BA++; BA < BB; BA++)
        sol += (int)B[BA].size() - (upper_bound(all(B[BA]), mxm) - B[BA].begin());
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        B[i/TB].push_back(arr[i]);
    }
    for(int i = 0; i < n; i += TB)
        sort(all(B[i/TB]));
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<query(a, b)<<"\n";
    }
    return 0;
}
