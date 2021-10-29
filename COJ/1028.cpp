#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,n;
    while(cin>>s>>n){
        int con=0,ca=0;
        for(int i=0;i<n.size();i++){
            if(s[ca]==n[i]){
                con++;
                ca++;
            }
        }
        if(con==s.size())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
