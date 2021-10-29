#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1;

long long table[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>table[i];
        table[i] += table[i - 1];
    }
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        int aux = lower_bound(table + 1, table + n + 1, a) - table;
        if(aux == n + 1) cout<<"none";
        else cout<<aux;
        cout<<"\n";
    }
    return 0;
}
