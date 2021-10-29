#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5;
int par[MAXn + 10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= MAXn; i++){
        (i % 2 ? par[i] = i + 1 : par[i] = i - 1);
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n % 2 == 0){
            for(int i = 1; i <= n; i++)
                cout<<par[i]<<" ";
        }
        else{
            for(int i = 1; i <= n - 2; i++)
                cout<<par[i]<<" ";
            cout<<n<<" "<<par[n - 1];
        }
        cout<<"\n";
    }
    return 0;
}
