#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int j = 1; j <= t; j++){
        int n;
        cin>>n;
        int sol = 1;
        for(int i = 2; i <= n; i++)
            sol *= i;
        cout<<"Case #"<<j<<": "<<sol<<"\n";
    }
    return 0;
}
