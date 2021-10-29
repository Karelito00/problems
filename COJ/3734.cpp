#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1, MOD = 1e9 + 7;

long long odd[MAXn];
long long even[MAXn];

int arr[MAXn];
int arr2[MAXn];
bool even_odd[MAXn];
unordered_map < int , int > mapa;
int n, con;

void comp_coord(){
    for(int i = 0 ; i < n; i++)
        arr2[i] = arr[i];
    sort(arr2, arr2 + n);
    con = 1;
    mapa[arr2[0]] = 1;
    for(int i = 1; i < n; i++){
        if(arr2[i] == arr2[i - 1]) continue;
        mapa[arr2[i]] = ++con;
    }
    for(int i = 0; i < n; i++){
        even_odd[i] = arr[i] % 2;
        arr[i] = mapa[arr[i]];
    }
}

long long query_odd(int pos){
    long long suma = 0;
    while(pos >= 1){
        suma = (suma + odd[pos]) % MOD;
        pos -= (pos&-pos);
    }
    return suma;
}

long long query_even(int pos){
    long long suma = 0;
    while(pos >= 1){
        suma = (suma + even[pos]) % MOD;
        pos -= (pos&-pos);
    }
    return suma;
}

void update_odd(int pos, long long val){
    while(pos <= con){
        odd[pos] = (odd[pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

void update_even(int pos, long long val){
    while(pos <= con){
        even[pos] = (even[pos] + val) % MOD;
        pos += (pos&-pos);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++) cin>>arr[i];
        comp_coord();
        long long sol = 0;
        for(int i = 0; i < n; i++){
            long long aux_odd = query_odd(arr[i] - 1);
            long long aux_even = query_even(arr[i] - 1);
            if(even_odd[i]){
                sol = (sol + aux_even + 1) % MOD;
                update_odd(arr[i], (aux_even + 1) % MOD);
                update_even(arr[i], aux_odd);
            }
            else{
                sol = (sol + aux_odd) % MOD;
                update_odd(arr[i], aux_odd);
                update_even(arr[i], (aux_even + 1) % MOD);
            }
        }
        cout<<sol<<"\n";
        fill(even + 1, even + con + 1, 0);
        fill(odd + 1, odd + con + 1, 0);
        mapa.clear();
    }
    return 0;
}
