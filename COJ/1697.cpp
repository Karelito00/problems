#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 3;
struct par{
    int a;
    int b;
    bool operator < (const par &var) const {
        return var.a > a;
    }
};

string p;
string pal;
int TF[MAXn];
vector < int > sol;
vector < int > sol2;
set < par > punt;
pair < int , int > comp[26];
short arr[MAXn];
short arr2[MAXn];
set < int > id[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, s;
    cin>>n>>k>>s;
    p = " ";
    pal = " ";
    int ant = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        if(i > 1){
            if(ant < arr[i])
                pal.push_back('<');
            else if(ant > arr[i])
                pal.push_back('>');
            else
                pal.push_back('=');
        }
        ant = arr[i];
    }
    for(int i = 1; i <= k; i++){
        cin>>arr2[i];
        punt.insert(par{arr2[i], i});
        if(i > 1){
            if(ant < arr2[i])
                p.push_back('<');
            else if(ant > arr2[i])
                p.push_back('>');
            else
                p.push_back('=');
        }
        ant = arr2[i];
    }
    if(k == 1){
        cout<<n<<"\n";
        for(int i = 1; i <= n; i++)
            cout<<i<<"\n";
        return 0;
    }
    int con = 0;
    for(auto x: punt){
        con++;
        comp[con] = mp(con, x.b);
    }
    int aux = 0;
    int TP = p.size();
    int TPAL = pal.size();
    for(int i = 2; i <= TP; i++){
        while(aux > 0 && p[aux + 1] != p[i])
            aux = TF[aux];
        if(p[i] == p[aux + 1])
            aux++;
        TF[i] = aux;
    }
    aux = 0;
    for(int i = 1; i <= TPAL; i++){
        while(aux > 0 && p[aux + 1] != pal[i])
            aux = TF[aux];
        if(p[aux + 1] == pal[i])
            aux++;
        if(aux + 1 == (int)p.size())
            sol.push_back(i - aux + 1);
    }
    int ini = *sol.begin(), fin = ini - 1;
    punt.clear();
    for(auto x: sol){
        int nx = x, ny = nx + k - 1;
        while(fin < ny){
            fin++;
            id[arr[fin]].insert(fin);
            if(id[arr[fin]].size() == 1)
                punt.insert(par{arr[fin], fin});
        }
        while(ini < nx){
            id[arr[ini]].erase(ini);
            punt.erase(par{arr[ini], ini});
            if(!id[arr[ini]].empty())
                punt.insert(par{arr[ini], *id[arr[ini]].begin()});
            ini++;
        }
        int cantt = 0;
        int jj = 0;
        for(auto h: punt)
            if(binary_search(comp + 1, comp + 1 + con, mp(++jj, h.b - x + 1))) cantt++;
        if(cantt == con)
            sol2.push_back(x);
    }
    cout<<sol2.size()<<"\n";
    for(auto x: sol2)
        cout<<x<<"\n";
    return 0;
}
