#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t,x;
    int a;
    cin>>a;
    for(int b=0;b<=a*2;b++){
        string s;
    getline(cin, s);
    if(b>=1 && b%2!=0){
        t=s;
    }
    else if(b>=1 && b%2==0){
        x=s;
    }
    if(b>=1 && b%2==0){
        for(int u=0;u<t.size();u++){
            if(t[u]!=' '){
                t[u]=x[t[u]-'A'];
            }
        }
        cout<<b/2<<" "<<t<<"\n";
    }
    }
    return 0;
}
