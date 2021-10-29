#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define base 29

using namespace std;

typedef unsigned long long ull;

int funt(char x){
    return x - 'a' + 1;
}

int const MAXn = 1001;
int TF[1001];
int k;
string s;
vector < string > pal;
unordered_map < ull , pair < int , int > > marc;
int sol;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>k>>s;
    int ts = s.size();
    for(int i = 0; i < ts; i++){
        ull hashing = 0;
        for(int j = i; j < ts; j++){
            hashing = (hashing * base) + funt(s[j]);
            marc[hashing].second++;
            marc[hashing].first = j - i + 1;
        }
    }
    for(auto p: marc){
        if(p.second.second == k)
            sol = mx(sol, p.second.first);
    }
    cout<<(sol == 0 ? -1 : sol);
    return 0;
}
