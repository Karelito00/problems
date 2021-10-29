#include <bits/stdc++.h>

using namespace std;

unordered_map < long long , long long > mapa;

long long recur(long long n){
    long long c1 = n / 2, c2 = n / 3, c3 = n / 4;
    if(c1 + c2 + c3 < n)
        return n;
    long long aux1 = (mapa.find(c1) != mapa.end() ? mapa[c1] : mapa[c1] = recur(c1));
    long long aux2 = (mapa.find(c2) != mapa.end() ? mapa[c2] : mapa[c2] = recur(c2));
    long long aux3 = (mapa.find(c3) != mapa.end() ? mapa[c3] : mapa[c3] = recur(c3));
    return aux1 + aux2 + aux3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        cout<<recur(n)<<"\n";
    }
    return 0;
}
