#include <bits/stdc++.h>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int c,d,e;
        cin>>c>>d>>e;
        if(d!=0 && (c/d==e || c%d==e))
            cout<<"YES\n";
        else if(c+d==e || c-d==e || c*d==e)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }

    return 0;
}
