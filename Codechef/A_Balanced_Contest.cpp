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
        int n, p;
        cin>>n>>p;
        int cake = p/2;
        int hard = p/10;
        int c = 0, h = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            if(x >= cake) c++;
            if(x <= hard) h++;
        }
        cout<<(c == 1 && h == 2 ? "yes" : "no")<<"\n";
    }
    return 0;
}
