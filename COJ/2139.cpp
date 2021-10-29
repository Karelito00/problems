#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,n;
    while(!cin.eof()){
        cin>>s>>n;
        if(cin.eof())
            break;
        int c=0;
        for(int i=0;i<n.size();i++){
            if(s[c]==n[i])
            c++;
        }
        if(c>=s.size())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
