#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 2e5 + 10;

struct par{
    int mili;
    int id;
    bool operator < (const par &var) const {
        return var.mili > mili;
    }
};

vector < par > teams;
unordered_map < int , int > mapa;

long long l , r = 1e10;
int n;

void SOLVE(){
    int ini = 0;
    mapa[teams[0].id]++;
    int con = 1;
    if(con == n){
        l = teams[0].mili;
        r = teams[0].mili;
        mapa[teams[0].id]--;
        con--;
        ini++;
    }
    for(int i = 1; i < (int)teams.size(); i++){
        if(!mapa[teams[i].id])
            con++;
        mapa[teams[i].id]++;
        while(con == n){
            if(teams[i].mili - teams[ini].mili < r - l){
                l = teams[ini].mili;
                r = teams[i].mili;
            }
            mapa[teams[ini].id]--;
            if(!mapa[teams[ini].id])
                con--;
            ini++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool mark = false;
    for(int i = 0; i < n; i++){
        int cant;
        cin>>cant;
        if(cant == 0) mark = true;
        while(cant--){
            int k;
            cin>>k;
            teams.push_back(par{k, i});
        }
    }
    if(mark){
        cout<<-1;
        return 0;
    }
    sort(all(teams));
    SOLVE();
    cout<<l<<" "<<r;
    return 0;
}
