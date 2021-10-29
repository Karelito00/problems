#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2, MOD = 1e9 + 7;

long long ABI[MAXn][MAXn];
int n;

void update(int l, int pos, long long val){
    while(pos <= n){
        ABI[l][pos] = (ABI[l][pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

long long query(int l, int pos){
    long long suma = 0;
    while(pos >= 1){
        suma = (ABI[l][pos] + suma) % MOD;
        pos -= (pos&-pos);
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
        int l, m;
        cin>>n>>l>>m;
        for(int i = 1; i <= n; i++)
            update(1, i, 1);
        for(int i = 1; i < l; i++){
            for(int j = 1; j <= n; j++){
                long long aux = (query(i, mn(j + m, n)) - query(i, j - m - 1) + MOD) % MOD;
                update(i + 1, j, aux);
            }
        }
        cout<<query(l, n)<<"\n";
        for(int i = 1; i <= l; i++)
            fill(ABI[i] + 1, ABI[i] + n + 1, 0);
    }
    return 0;
}
