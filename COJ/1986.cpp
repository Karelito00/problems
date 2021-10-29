#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 5e4 + 2;

pair < int , int > arr[MAXn];

unordered_map < int , int > mapa;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int raz = 0;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i].f>>arr[i].s;
        if(mapa.find(arr[i].s) == mapa.end()){
            raz++;
            mapa[arr[i].s];
        }
    }
    sort(arr + 1, arr + n + 1);
    int l = 1, r = 1;
    int con = 0;
    int sol = INT_MAX;
    while(r <= n){
        mapa[arr[r].s]++;
        if(mapa[arr[r].s] == 1) con++;
        r++;
        while(con == raz){
            sol = mn(sol, arr[r - 1].f - arr[l].f);
            mapa[arr[l].s]--;
            if(!mapa[arr[l].s])
                con--;
            l++;
        }
    }
    cout<<sol;
    return 0;
}
