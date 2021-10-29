#include <bits/stdc++.h>

using namespace std;

int main()
{
   
    string a,b;
    cin>>a>>b;
    for(int x=0;x<b.size();x++){
    a.push_back(b[x]);
    }
    string l=a;
    reverse(a.begin(),a.end());
    if(l==a)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
