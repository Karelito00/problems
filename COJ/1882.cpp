#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < string , int > mapa;
string sol;
string h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i = 0; i < (int)s.size(); i++){
        if(i > 7)
            h = h.substr(1);
        h.push_back(s[i]);
        if(i >= 7)
            mapa[h]++;
    }
    int best = 1;
    for(auto x: mapa){
        if(x.second > best){
            best = x.second;
            sol = x.first;
        }
        else if(x.second == best)
            sol = mn(sol, x.first);
    }
    cout<<(best >= 2 ? sol : "Solution was not found");
    return 0;
}
