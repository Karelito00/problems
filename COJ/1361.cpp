#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < int , bool > mapa;
vector < int > number;
int const MAXm = 1e8;

int SOLVE(int a, int b){
    return (upper_bound(all(number), b) - number.begin()) - (lower_bound(all(number), a) - number.begin());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i * i * i <= MAXm; i++)
        mapa[i * i * i] = true;
    for(int i  = 1; i * i <= MAXm; i++)
        if(mapa.find(i * i) != mapa.end())
            number.push_back(i * i);

    int a, b;
    while(cin>>a>>b){
        cout<<SOLVE(a,b)<<"\n";
    }
    return 0;
}
