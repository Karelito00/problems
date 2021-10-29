#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6;

int fs[(MAXn * 2) + 5];
int suma, sol;
int n;

int main()
{
    freopen("codbar.in","r",stdin);
    freopen("codbar.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    fs[MAXn] = 1;
    for(int i = 1; i <= n; i++){
        char a;
        cin>>a;
        suma += (a == '0' ? -1 : 1);
        sol += fs[suma + MAXn]++;
    }
    cout<<sol;
    return 0;
}
