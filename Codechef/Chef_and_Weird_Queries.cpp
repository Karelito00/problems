#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long const MAXn = 1e10, ll = 700;

vector < long long > num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 1; i * i <= MAXn; i++)
        num.push_back(i * i);
    int t;
    cin>>t;
    while(t--){
        long long y;
        cin>>y;
        int pos = upper_bound(all(num), y - ll) - num.begin();
        long long suma = 0;
        for(int i = pos; i < (int)num.size() && num[i] < y; i++){
            suma += y - num[i];
        }
        suma += (pos * ll);
        cout<<suma<<"\n";
    }
    return 0;
}
