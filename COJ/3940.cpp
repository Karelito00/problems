#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 10, MOD = 1e9 + 7;

long long arr[MAXn];
long long arr2[MAXn];
int n;
unordered_map < long long , int > mapa;
int con;

void comp_coord(){
    for(int i = 0; i < n; i++)
        arr2[i] = arr[i];
    sort(arr2, arr2 + n);
    con = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && arr2[i] != arr2[i - 1]) con++;
        mapa[arr2[i]] = con;
    }
    for(int i = 0; i < n; i++)
        arr[i] = mapa[arr[i]];
    con++;
}

long long ABI[MAXn];

void update(int pos, long long val){
    while(pos <= con){
        ABI[pos] = (ABI[pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long suma = 0;
    while(pos > 0){
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
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        comp_coord();
        long long sol = 0;
        long long aux = 0;
        for(int i = 0; i < n; i++){
            aux = (sol - query(arr[i]) + 1 + MOD) % MOD;
            sol = (sol + aux) % MOD;
            update(arr[i], aux);
        }
        cout<<sol<<"\n";
        fill(ABI + 1, ABI + con + 1, 0);
        mapa.clear();
    }
    return 0;
}
