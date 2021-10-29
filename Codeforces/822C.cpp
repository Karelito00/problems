#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int n;
long long x;

struct karel{
    long long l,r,c,dif;
    bool operator < (const karel &hola)const{
        if(hola.dif != dif)
            return hola.dif > dif;
        return hola.l > l;
    }
}z[200001];
int cant;
long long dp[200001][18];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int l,r,c;
        cin>>l>>r>>c;
        if(r - l + 1 >= x)
            continue;
        cant++;
        z[cant] = karel{l,r,c,r-l+1};
    }
    sort(z+1,z+cant+1);
    for(int i=1;i<=cant;i++)
        dp[i][0] = z[i].c;
    for(int e=1;(1<<e)<=cant;e++){
        for(int j=1;j<=cant-(1<<e)+1;j++){
            dp[j][e] = mn(dp[j][e-1], dp[j+(1<<(e-1))][e-1]);
        }
    }
    long long best = 1e18;
    for(int i=1;i<=cant;i++){
        long long diff = x - z[i].dif;
        int ini = lower_bound(z+1,z+cant+1,karel{0,0,0,diff}) - z;
        if(z[ini].dif != diff)
            continue;
        int fin = upper_bound(z+1,z+cant+1,karel{INT_MAX,0,0,diff}) - z - 1;
        int fin2 = upper_bound(z+ini,z+fin+1,karel{z[i].r,0,0,diff}) - z;
        if(fin2 > fin) continue;
        int lg = log2(fin - fin2 + 1);
        best = mn(best,z[i].c + mn(dp[fin2][lg],dp[fin-(1<<lg)+1][lg]));
    }
    cout<<(best == 1e18 ? -1 : best);
    return 0;
}
