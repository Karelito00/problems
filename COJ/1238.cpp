#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
    string s;
    cin>>s;
    if(s=="0")
        break;
    int o=s.size();
    int sumat=0;
    for(int j=0;j<s.size();j++){
        int suma=1;
        for(int h=o;h>=1;h--){
            suma*=h;
        }
        sumat+=(suma*(s[j]-'0'));
     o--;
    }
    cout<<sumat<<"\n";
    }
    return 0;
}
