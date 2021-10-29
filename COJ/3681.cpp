#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 1, MAXm = 79000, loga = log2(MAXm) + 2;

vector < int > prim;
bool criba[MAXn];
int RMQ[MAXm][loga];

vector < int > ini;
vector < int > fin;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 2; i * i <= MAXn; i++){
        if(!criba[i]) for(int j = i * i; j <= MAXn; j += i) criba[j] = true;
    }
    for(int i = 2; i <= MAXn; i++)
        if(!criba[i]) prim.push_back(i);
    for(int i = 2; i < (int)prim.size(); i++){
        ini.push_back(prim[i - 2]);
        fin.push_back(prim[i]);
        RMQ[i - 1][0] = prim[i] - prim[i - 2] + 1;
    }
    int nn = prim.size() - 2;
    for(int e = 1; e <= log2(nn); e++){
        for(long long i = 1; i + (1LL<<e) - 1 <= nn; i++)
            RMQ[i][e] = mn(RMQ[i][e - 1], RMQ[i + (1LL<<(e - 1))][e - 1]);
    }
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int ii = lower_bound(all(ini), a) - ini.begin();
        int ff = upper_bound(all(fin), b) - fin.begin() - 1;
        ii++, ff++;
        if(ff < ii){
            cout<<"-1\n";
            continue;
        }
        int lg = log2(ff - ii + 1);
        cout<<mn(RMQ[ii][lg], RMQ[ff - (1<<lg) + 1][lg])<<"\n";
    }
    return 0;
}
