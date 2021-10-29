#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 2;

bool criba[MAXn];
vector < int > primos;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i = 2; i * i <= n; i++){
        for(int j = i * 2; j <= n; j += i)
            criba[j] = true;
    }
    int sol = 0;
    for(int i = 2; i <= n; i++)
        if(!criba[i]) primos.push_back(i);
    for(int i = 0; i < (int)primos.size() - 1; i++){
        int aux = primos[i] + primos[i + 1] + 1;
        if(aux > n) break;
        if(!criba[aux]) sol++;
    }
    if(sol >= k) cout<<"YES";
    else cout<<"NO";
    return 0;
}
