#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int TF[28];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int ts = s.size();
    s = " " + s;
    int aux = 0;
    for(int i = 2; i <= ts; i++){
        while(aux > 0 && s[aux + 1] != s[i])
            aux = TF[aux];
        if(s[aux + 1] == s[i]) aux++;
        TF[i] = aux;
    }
    string p;
    int con = 0;
    while(cin >> p){
        int tp = p.size();
        aux = 0;
        for(int i = 0; i < tp; i++){
            while(aux > 0 && s[aux + 1] != p[i])
                aux = TF[aux];
            if(s[aux + 1] == p[i])
                aux++;
            if(aux == ts)
                con++;
        }
    }
    cout<<con;
    return 0;
}
