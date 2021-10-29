#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        long long h;
        cin>>h;
        string s;
        while(h>0){
            s.push_back((h%2)+'0');
            h/=2;
        }
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
