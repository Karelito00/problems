#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
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
        string sol;
        int pal = n/p;
        if(p == 1){
            cout<<"impossible\n";
            continue;
        }
        if(p == 2){
            cout<<"impossible\n";
            continue;
        }
        if(p == n){
            string sol(n, 'a');
            if(n&1) sol[n/2] = 'b';
            else sol[0] = sol[n - 1] = 'b';
            cout<<sol;
        }
        else{
            sol = 'a';
            int con = 1;
            for(; con < p - 1; con++)
                sol.push_back('b');
            sol.push_back('a');
            for(int i = 0; i < pal; i++)cout<<sol;
        }
        cout<<"\n";
    }
    return 0;
}
