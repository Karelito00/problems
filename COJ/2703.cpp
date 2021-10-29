#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2, MOD = 1e9 + 7;

long long ABI[MAXn];
int arr[MAXn];
int n;

void update(int pos, long long val){
    while(pos <= n){
        ABI[pos] = (ABI[pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long suma = 0;
    while(pos >= 1){
        suma = (suma + ABI[pos]) % MOD;
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
    cin>>n;
    for(int i = 2; i <= n; i++)
        cin>>arr[i];
    update(n, 1);
    for(int i = n; i >= 2; i--){
        long long aux = query(i);
        update(mx(i - arr[i], 1), aux);
        update(i, -aux + MOD);
    }
    cout<<ABI[1];
    return 0;
}
