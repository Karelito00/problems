#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define base 29

using namespace std;

typedef unsigned long long ull;

unordered_map < ull , bool > mapa;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int tm = s.size();
    int sol = 0;
    for(int i = 0; i < tm; i++){
        ull suma = 0;
        for(int j = i; j < tm; j++){
            suma = (suma * base) + (s[j] - 'a' + 1);
            if(!mapa[suma]){
                sol++;
                mapa[suma] = true;
            }
        }
    }
    cout<<sol;
    return 0;
}
