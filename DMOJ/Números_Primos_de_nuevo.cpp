#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6;

bool criba[MAXn + 2];

vector < int > primos;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i * i <= MAXn; i++){
        for(int j = i * 2; j <= MAXn; j += i)
            criba[j] = true;
    }
    for(int i = 2; i <= MAXn; i++){
       if(!criba[i]){
            primos.push_back(i);
            if(i > 1e5) break;
       }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int aux = lower_bound(all(primos), n) - primos.begin();
        cout<<(primos[aux] == n ? n : primos[aux - 1])<<" "<<primos[aux]<<"\n";
    }
    return 0;
}
