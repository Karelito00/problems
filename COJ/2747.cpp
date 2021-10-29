#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < int , bool > comb;
unordered_map < int , bool > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long sol = 0;
    for(int i = 0; i < n; i++){
        int l;
        cin>>l;
        if(i > 0){
            for(auto x: comb){
                if(mapa.find(l - x.first) != mapa.end()){
                    sol++;
                    break;
                }
            }
        }
        mapa[l] = true;
        for(auto x: mapa)
            comb[l + x.first] = true;
    }
    cout<<sol;
    return 0;
}
