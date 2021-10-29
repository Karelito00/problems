#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int price[27];
bool letras[27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i = 0; i < 26; i++)
            cin>>price[i];
        string s;
        cin>>s;
        int sol = 0;
        for(auto x: s)
            letras[x - 'a'] = true;
        for(int i = 0; i < 26; i++){
            if(!letras[i])
                sol += price[i];
            letras[i] = false;
        }
        cout<<sol<<"\n";
    }
    return 0;
}
