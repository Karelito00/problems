#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 10;
long long table[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long best = 1e10;
        int index = 0;
        for(int i = 1; i <= n; i++){
            cin>>table[i];
            table[i] += table[i - 1];
        }
        for(int i = 1; i <= n; i++){
            if(table[i] + (table[n] - table[i - 1]) < best){
                best = table[i] + (table[n] - table[i - 1]);
                index = i;
            }
        }
        cout<<index<<"\n";
    }
    return 0;
}
