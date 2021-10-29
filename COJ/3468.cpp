#include <bits/stdc++.h>

using namespace std;
string z[10001];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        z[b]=s;
    }
    cout<<0<<"\n";
    for(int y=1;y<a;y++){
            int c=0;
    string h=z[y];
        for(int x=y-1;x>=0;x--){
            string l=z[x];
            if(h==l)
                c++;
        }
        cout<<c<<"\n";
    }
    return 0;
}
