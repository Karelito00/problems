#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int n;
vector < int > adya[202];
int sol[202][2];
bool pos[202][2];

void DFS(int v){
    for(auto to: adya[v])
        DFS(to);
    sol[v][0] = 1;
    for(auto to: adya[v]){
        sol[v][0] += sol[to][1];
        sol[v][1] += mx(sol[to][1], sol[to][0]);
        pos[v][0] |= pos[to][1];
        if(sol[to][1] == sol[to][0])
            pos[v][1] = true;
        else if(sol[to][1] > sol[to][0])
            pos[v][1] |= pos[to][1];
        else
            pos[v][1] |= pos[to][0];
    }
}

unordered_map < string , int > has;

string funt(bool x){
    if(x) return "No";
    else return "Yes";
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>n;
        if(n == 0) return 0;
        string boss;
        cin>>boss;
        int con = 0;
        has[boss] = ++con;
        for(int i = 1; i < n; i++){
            string n1, n2;
            cin>>n1>>n2;
            if(has.find(n1) == has.end())
                has[n1] = ++con;
            if(has.find(n2) == has.end())
                has[n2] = ++con;
            adya[has[n2]].push_back(has[n1]);
        }
        DFS(1);
        if(sol[1][0] > sol[1][1])
            cout<<sol[1][0]<<" "<<funt(pos[1][0]);
        else if(sol[1][0] < sol[1][1])
            cout<<sol[1][1]<<" "<<funt(pos[1][1]);
        else
            cout<<sol[1][1]<<" "<<"No";
        cout<<"\n";
        for(int i = 1; i <= n; i++){
            adya[i].clear();
            sol[i][1] = sol[i][0] = 0;
            pos[i][1] = false;
            pos[i][0] = false;
        }
        has.clear();
    }
    return 0;
}
