#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e6 + 10;

map < int , int > mapa;
int ABI[MAXn];
int n;

void update(int pos){
    while(pos <= n){
        ABI[pos]++;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sol = 0;
    while(pos >= 1){
        sol += ABI[pos];
        pos -= (pos&-pos);
    }
    return sol;
}

int arr[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long sol = 0;
    int con = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        mapa[arr[i]];
    }
    for(auto x: mapa)
        mapa[x.first] = ++con;
    for(int i = n; i >= 1; i--){
        sol += query(mapa[arr[i]]);
        update(mapa[arr[i]]);
    }
    cout<<sol;
    return 0;
}
