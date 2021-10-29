#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 10;
int TF[MAXn];
int TS[MAXn];

int main()
{
    freopen("main.in","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, p;
    cin>>s>>p;
    int ts = s.size();
    int tp = p.size();
    s = " " + s;
    p = " " + p;
    int aux = 0;
    for(int i = 2; i <= tp; i++){
        while(aux > 0 && p[i] != p[aux + 1])
            aux = TF[aux];
        if(p[aux + 1] == p[i])
            aux++;
        TF[i] = aux;
    }
    string sol = " ";
    aux = 0;
    for(int i = 1; i <= ts; i++){
        sol += s[i];
        while(aux > 0 && p[aux + 1] != sol.back())
            aux = TF[aux];
        if(sol.back() == p[aux + 1])
            aux++;
        TS[sol.size() - 1] = aux;
        if(aux == (int)p.size() - 1){
            sol.resize(sol.size() - p.size() + 1);
            aux = TS[sol.size() - 1];
        }
    }
    cout<<sol.substr(1);
    return 0;
}
