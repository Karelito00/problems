#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        if((s[s.size()-1]-'0')%2==0)
            cout<<"even\n";
        else
            cout<<"odd\n";
    }
    return 0;
}
