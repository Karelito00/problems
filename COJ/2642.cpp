#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e4;

int mod[MAXn + 10];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod[0] = 1;
    for(int i = 1; i <= MAXn; i++){
        mod[i] = (mod[i - 1] * 2) % 3;
    }
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int tm = s.size() - 1;
        int suma = 0;
        for(int i = 0; i <= tm; i++){
            if(s[i] == '1')
                suma += mod[tm - i];
        }
        cout<<(suma % 3 ? "NO" : "YES")<<"\n";
    }
    return 0;
}
