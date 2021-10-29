#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unsigned long long table[64];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    table[0] = 1;
    for(int i = 1; i < 64; i++)
        table[i] = table[i - 1] * 2;
    int t;
    cin>>t;
    while(t--){
        long long n, m;
        int i;
        cin>>n>>m>>i;
        int y = i;
        int pos = (31 - __builtin_clz(m)) + i;
        for(; i <= pos; i++){
            bool btn = n&table[i];
            bool btm = m&table[i - y];
            if(!btm && btn) n ^= (table[i]);
            else if(btm && !btn) n |= (table[i]);
        }
        cout<<n<<"\n";
    }
    return 0;
}
