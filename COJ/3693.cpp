#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long const MAXn = 1e9;

long long b, x;

long long SOLVE(){
    long long o = b - 1;
    bool mark = true;
    if(o > MAXn || o <= 0)
        mark = false;
    for(int i = 1; i <= x; i++){
        o = (o * 2) - b;
        if(o > MAXn || o <= 0)
            mark = false;
        if((b + o) % 2 == 1)
            mark = false;
    }
    if(mark)
        return o;
    o = b + 1;
    mark = true;
    if(o > MAXn || o <= 0)
        mark = false;
    for(int i = 1; i <= x; i++){
        o = (o * 2) - b;
        if(o > MAXn || o <= 0)
            mark = false;
        if((b + o) % 2 == 1)
            mark = false;
    }
    if(mark)
        return o;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>b>>x;
        if(!x)
            cout<<(b == 1 ? 2 : b - 1);
        else
            cout<<SOLVE();
        cout<<"\n";
    }
    return 0;
}
