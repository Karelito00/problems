#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int ascii(char h){
    return h - '0';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s,x;
        cin>>s>>x;
        string j;
        reverse(all(s));
        reverse(all(x));
        int tm = mn(s.size(), x.size());
        for(int i = 0; i < tm; i++){
            int a = ascii(s[i]);
            int b = ascii(x[i]);
            j.push_back(((a + b) % 10) + '0');
        }
        if((int)s.size() > (int)x.size()){
            for(int i = tm; i < (int)s.size(); i++)
                j.push_back(s[i]);
        }
        else{
            for(int i = tm; i < (int)x.size(); i++)
                j.push_back(x[i]);
        }
        reverse(all(j));
        int pos = 0;
        while(j[pos] == '0') pos++;
        if(pos == j.size())
            cout<<0;
        else{
            for(; pos < j.size(); pos++) cout<<j[pos];
        }
        cout<<"\n";
    }
    return 0;
}
