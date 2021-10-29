#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 26;

unordered_map < int , vector < int > > mapa;
int arr[MAXn];
int x, n;

string SOLVE(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(auto k: mapa[arr[i]^arr[j]^x])
                if(k != i && k != j) return "YES";
        }
    }
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        mapa[arr[i]].push_back(i);
    }
    cout<<SOLVE();
    return 0;
}
