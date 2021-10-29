#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1001;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int c = 0, a = 0;
        int sol = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'C')
                c++;
            else if(s[i] == 'A')
                a += c;
            else if(s[i] == 'T')
                sol += a;
        }
        cout<<sol<<"\n";
    }
    return 0;
}
