#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 2e6 + 2;

long long table[MAXn];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        int b, pos;
        cin>>b>>pos;
        table[pos] = b;
    }
    for(int i = 1; i <= MAXn - 2; i++)
        table[i] += table[i - 1];
    long long sol = 0;
    for(int i = 0; i <= MAXn - 2; i++){
        long long aux = 0;
        if(i - k - 1 < 0) aux += table[i];
        else aux += table[i] - table[i - k - 1];
        if(i + k > MAXn - 2) aux += table[MAXn] - table[i];
        else aux += table[i + k] - table[i];
        sol = mx(sol, aux);
    }
    cout<<sol;
    return 0;
}
