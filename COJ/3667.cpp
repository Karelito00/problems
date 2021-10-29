#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int TF[2500];

string sol;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string p;
        cin>>p;
        if(i == 0){
            sol += p;
            continue;
        }
        int tp = p.size();
        p = " " + p;
        TF[1] = 0;
        for(int i = 2; i <= tp; i++){
            int aux = TF[i - 1];
            while(aux > 0 && p[aux + 1] != p[i]) aux = TF[aux];
            if(p[aux + 1] == p[i])
                aux++;
            TF[i] = aux;
        }
        int aux = 0;
        for(int i = mx((int)sol.size() - tp, 0); i < (int)sol.size(); i++){
            while(aux > 0 && sol[i] != p[aux + 1])
                aux = TF[aux];
            if(p[aux + 1] == sol[i])
                aux++;
        }
        aux++;
        for(;aux <= tp; aux++)
            sol.push_back(p[aux]);
    }
    for(int i = 0; i < (int)sol.size(); i++)
        cout<<sol[i];
    return 0;
}
