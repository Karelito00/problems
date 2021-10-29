#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define all(v) (v).begin(),(v).end()
#define base 29

using namespace std;

typedef unsigned long long ull;
int const MAXn = 1e5 + 2;

ull hashing[MAXn];
ull hashingrev[MAXn];

bool funt(char x){
    if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return true;
    return false;
}

ull powm[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    powm[0] = 1;
    for(int i = 1; i <= MAXn - 2; i++){
        powm[i] = powm[i - 1] * base;
    }
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int tm = s.size();
        int voc = INT_MAX;
        for(int i = 0; i < tm; i++){
            if(voc == INT_MAX && funt(s[i]))
                voc = i + 1;
            hashing[i + 1] = hashing[i] * base + (s[i] - 'A' + 1);
            hashingrev[i + 1] = hashingrev[i] * base + (s[tm - i - 1] - 'A' + 1);
        }
        int sol = 0;
        for(int i = voc; i <= tm; i++){
            ull aux = hashingrev[tm] - (hashingrev[tm - i] * (powm[i]));
            if(aux == hashing[i])
                sol++;
        }
        cout<<sol<<"\n";
    }
    return 0;
}
