#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l;
    cin>>l;
    for(int t=0;t<l;t++){
    string a,s;
    cin>>a>>s;
    int c=0;
    for(int b=0;b<a.size();b++){
     if(a[b]!=s[b])
        c++;
    }
    cout<<c<<"\n";
    }

    return 0;
}
