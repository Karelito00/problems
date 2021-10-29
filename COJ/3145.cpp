#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 5e4 + 10;
int table[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>table[i];
        table[i] += table[i - 1];
    }
    while(q--){
        int note;
        cin>>note;
        cout<<upper_bound(table + 1, table + n + 1, note) - table<<"\n";
    }
    return 0;
}
