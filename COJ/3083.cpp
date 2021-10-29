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
    int n;
    cin>>n;
    string sol;
    int num = INT_MAX;
    for(int i = 0; i < n; i++){
        string s;
        int x, y;
        cin>>s>>x>>y;
        if((x * x) + (y * y) < num){
            num = (x * x) + (y * y);
            sol = s;
        }
    }
    cout<<sol;
    return 0;
}
