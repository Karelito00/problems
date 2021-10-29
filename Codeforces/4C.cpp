#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
int const base = 113;

map < ull , pair < int , string > > mapa;
ull hashing1(string s){
    ull hashing = 0;
    for(int i=0;i<(int)s.size();i++){
        hashing = (hashing * base) + s[i];
    }
    return hashing;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ull hashing = hashing1(s);
        if(mapa.find(hashing) == mapa.end()){
            mapa[hashing] = make_pair(0,s);
            cout<<"OK\n";
        }
        else{
            int o = mapa[hashing].first + 1;
            int e = o;
            string k;
            while(o>0){
                k.push_back((o%10)+'0');
                o/=10;
            }
            reverse(k.begin(),k.end());
            s += k;
            ull nw = hashing1(s);
            mapa[nw] = make_pair(e,s);
            mapa[hashing].first++;
            cout<<s<<"\n";
        }
    }
    return 0;
}

