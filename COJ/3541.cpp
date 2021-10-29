#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    for(int u=0;u<n;u++){
        getline(cin,s);
        for(int i=0;i<(int)s.size();i++){
            if(s[i]>='A' && s[i]<='Z')
                cout<<(char)(s[i]+32);
            else if(s[i]>='a' && s[i]<='z')
                cout<<(char)(s[i]-32);
            else
                cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}
