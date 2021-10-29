#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

vector < int > adya[2001];

bool visited[2001];
int maxlvl;

void DFS(int n, int l){
    maxlvl = mx(maxlvl, l);
    for(auto x: adya[n]){
        if(!visited[x]){
            visited[x] = true;
            DFS(x, l + 1);
        }
    }
}

vector < int > nod;

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        if(x == -1){
            nod.push_back(i);
            continue;
        }
        adya[i].push_back(x);
        adya[x].push_back(i);
    }
    for(auto i: nod){
        if(!visited[i]){
            visited[i] = true;
            DFS(i, 1);
        }
    }
    cout<<maxlvl;
    return 0;
}
