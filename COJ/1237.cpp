#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        int y=b-a;
        cout<<a-y<<"\n";
    }
    return 0;
}
