#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < int , vector < int > > mapa;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int k = 1; k <= n; k++){
        int x;
        cin>>x;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                mapa[i].push_back(k);
                if(x / i != i)
                    mapa[x / i].push_back(k);
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a, b, k;
        cin>>a>>b>>k;
        int aux = lower_bound(all(mapa[k]), a) - mapa[k].begin();
        cout<<(upper_bound(all(mapa[k]), b) - mapa[k].begin()) - aux<<"\n";
    }
    return 0;
}
