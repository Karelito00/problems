#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 10, NM = 1e9;
long long x[MAXn];
long long y[MAXn];
long long tablex[MAXn];
long long tabley[MAXn];

int main()
{
    freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0 ; i < n; i++){
        cin>>x[i]>>y[i];
        x[i] += NM;
        y[i] += NM;
    }
    sort(x, x + n);
    sort(y, y + n);
    tablex[0] = x[0];
    tabley[0] = y[0];
    for(int i = 1; i < n; i++){
        tablex[i] = tablex[i - 1] + x[i];
        tabley[i] = tabley[i - 1] + y[i];
    }
    int q;
    cin>>q;
    while(q--){
        long long x1, y1;
        cin>>x1>>y1;
        x1 += NM;
        y1 += NM;
        int pos = upper_bound(x, x + n, x1) - x;
        long long left = tablex[pos - 1];
        long long right = tablex[n - 1] - tablex[pos - 1];
        long long suma = abs((x1 * pos) - left) + abs((x1 * (n - pos)) - right);
        pos = upper_bound(y, y + n, y1) - y;
        long long up = tabley[pos - 1];
        long long down = tabley[n - 1] - tabley[pos - 1];
        cout<<suma + abs((y1 * pos) - up) + abs((y1 * (n - pos)) - down)<<"\n";
    }
    return 0;
}
