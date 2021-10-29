#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long id[103];
long long table[10002];
unordered_map < long long , int > mapa;
unordered_map < long long , bool > ll;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>id[i];
        ll[id[i]] = true;
    }
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>table[i];
        table[i] += table[i - 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            long long aux = table[j] - table[i - 1];
            if(ll.find(aux) != ll.end())
                mapa[aux]++;
        }
    }
    for(int i = 1; i <= t; i++)
        cout<<mapa[id[i]]<<"\n";
    return 0;
}
