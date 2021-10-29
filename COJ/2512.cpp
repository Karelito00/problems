#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7, MAXn = 5e5 + 2;

struct pr{
    int f;
    int s;
    bool operator < (const pr &var) const {
        return (var.f != f ? var.f > f : var.s < s);
    }
};

long long dp[35][13];
int tam[35];
vector < pr > dig[13];
int con, sz;
int arr[12];

void funt(long long num){
    ++con;
    sz = 0;
    while(num > 0){
        arr[sz] = num % 10;
        num /= 10;
        sz++;
    }
    reverse(arr, arr + sz);
    for(int i = 0; i < sz; i++)
        dig[arr[i]].push_back(pr{con, i});
    tam[con] = sz;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pw = 1;
    funt(pw);
    for(int i = 1; i <= 32; i++){
        pw *= 2;
        funt(pw);
    }
    for(int i = 0; i <= 9; i++)
        sort(all(dig[i]));
    string s;
    cin>>s;
    for(auto x: s){
        int k = x - '0';
        for(auto par: dig[k]){
            if(par.s == 0)
                dp[par.f][par.s] = (dp[par.f][par.s] + 1LL) % MOD;
            else
                dp[par.f][par.s] = (dp[par.f][par.s] + dp[par.f][par.s - 1]) % MOD;
        }
    }
    long long sol = 0;
    for(int i = 1; i <= con; i++)
        sol = (sol + dp[i][tam[i] - 1]) % MOD;
    cout<<sol;
    return 0;
}
