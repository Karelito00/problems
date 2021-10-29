#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("pal.in","r",stdin);
    freopen("pal.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    string h;
    int tam=0;
    for(int i=0;i<s.size();i++){
        for(int u=0;u<=s.size();u++){
            string k = s.substr(i,u);
            string j=k;
            reverse(j.begin(),j.end());
            if(j==k && tam<j.size()){
                h=j;
                tam=j.size();
            }
        }
        s.erase(0,0);
    }
    cout<<h;
    return 0;
}
