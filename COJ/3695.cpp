#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e9;

unordered_map < int , bool > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i <= sqrt(MAXn); i++){
        for(long long j = i * i; j <= MAXn; j *= i)
            mapa[j] = true;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sol = 0;
        for(long long i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(mapa.find(n/i) != mapa.end()) sol++;
                if(i != n/i && mapa.find(i) != mapa.end()) sol++;
            }
        }
        cout<<sol<<"\n";
    }
    return 0;
}
