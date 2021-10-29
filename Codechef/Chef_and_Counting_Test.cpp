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
    while(t--){
        string s;
        cin>>s;
        if((int)s.size() == 1){
            cout<<0<<"\n";
            continue;
        }
        int tam = s.size();
        long long con = 1;
        long long sol = 0;
        for(int i = 1; i < tam; i++){
            if(s[i] == s[i - 1]){
                con++;
                continue;
            }
            sol += (con * (con - 1)) / 2;
            if(i - con > 0 && s[i] == s[i - con - 1]) sol++;
            con = 1;
        }
        sol += (con * (con - 1)) / 2;
        cout<<sol<<"\n";
    }
    return 0;
}
