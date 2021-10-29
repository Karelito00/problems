#include <bits/stdc++.h>

using namespace std;

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
        if(s.size()<11)
            cout<<s<<"\n";
        else
            cout<<s[0]<<s.size()-2<<s[s.size()-1]<<"\n";
    }
    return 0;
}
