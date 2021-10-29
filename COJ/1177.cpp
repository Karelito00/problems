#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int n;
        cin>>n;
        if(n==0)
            break;
        string s;
        cin>>s;
        int h=s.size();
        string new_s;
        for(int u=0;u<n;u++){
            string j=s.substr(0,h/n);
            s.erase(0,h/n);
            reverse(j.begin(),j.end());
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}
