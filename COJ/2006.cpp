#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < int , int > par;
int const MAXn = 2e3 + 3, loga = log2(MAXn) + 2;

vector < par > val;

par arr[MAXn];
long long dp[MAXn];
int RMQ[MAXn][loga];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin>>n>>l;
    for(int i = 1; i <= n; i++){
        cin>>arr[i].f>>arr[i].s;
        RMQ[i][0] = arr[i].f;
    }
    for(int e = 1; (1<<e) <= n; e++){
        for(int i = 1; i + (1<<e) - 1 <= n; i++)
            RMQ[i][e] = mx(RMQ[i][e - 1], RMQ[i + (1<<(e - 1))][e - 1]);
    }
    fill(dp + 1, dp + n + 1, 1LL * INT_MAX * INT_MAX);
    long long aux1 = 0;
    for(int j = 1; j <= n; j++){
        aux1 += arr[j].s;
        if(aux1 > l) break;
        int lg = log2(j);
        dp[j] = mx(RMQ[1][lg], RMQ[j - (1<<lg) + 1][lg]);
    }
    for(int i = 2; i <= n; i++){
        long long suma = 0;
        for(int j = i; j <= n; j++){
            suma += arr[j].s;
            if(suma > l) break;
            val.push_back(mp(i, j));
        }
    }
    for(int i = 1; i < n; i++){
        int pos = lower_bound(all(val), mp(i + 1, 0)) - val.begin();
        for(; pos < (int)val.size() && val[pos].f == i + 1; pos++){
            int lg = log2(val[pos].s - val[pos].f + 1);
            int aux = mx(RMQ[val[pos].f][lg], RMQ[val[pos].s - (1<<lg) + 1][lg]);
            dp[val[pos].s] = mn(dp[val[pos].s], dp[i] + aux);
        }
    }
    cout<<dp[n];
    return 0;
}
