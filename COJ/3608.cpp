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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        if(a > b)
            swap(a, b);
        if(a == b && (a == 1 || a == 2)){
            cout<<2<<"\n";
            continue;
        }
        if((a == 3 || a == 4) && b != a){
            cout<<1<<"\n";
            continue;
        }
        else if((a == 3 || a == 4)){
            cout<<2<<"\n";
            continue;
        }
        if(b > a){
            cout<<1<<"\n";
            continue;
        }
        cout<<2<<"\n";
    }
    return 0;
}
