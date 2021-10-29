#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 2;

int TF[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int u = 1; u <= t; u++){
        string s, p;
        cin>>s>>p;
        int ts = s.size(), tp = p.size();
        s = " " + s;
        p = " " + p;
        int aux = 0;
        for(int i = 2; i <= tp; i++){
            while(aux > 0 && p[aux + 1] != p[i])
                aux = TF[aux];
            if(p[aux + 1] == p[i])
                aux++;
            TF[i] = aux;
        }
        aux = 0;
        int sol = 0;
        for(int i = 1; i <= ts; i++){
            while(aux > 0 && s[i] != p[aux + 1])
                aux = TF[aux];
            if(p[aux + 1] == s[i])
                aux++;
            if(aux == tp)
                sol++;
        }
        cout<<"Case "<<u<<": "<<sol<<"\n";
    }
    return 0;
}
