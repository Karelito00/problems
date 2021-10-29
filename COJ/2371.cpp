#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

vector < int > num;
int const MAXn = 1e9;
unordered_map < int , bool > mapa;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    num.push_back(1);
    for(long long i = 2; i * i <= MAXn; i++){
        long long aux = i * i;
        while(aux <= MAXn){
            if(!mapa[aux])
                num.push_back(aux);
            mapa[aux] = true;
            aux *= i;
        }
    }
    sort(all(num));
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        int a, b;
        cin>>a>>b;
        int aux = upper_bound(all(num), b) - num.begin() - 1;
        cout<<"Case "<<i<<": ";
        cout<<aux - (lower_bound(all(num), a) - num.begin() - 1)<<"\n";
    }
    return 0;
}
