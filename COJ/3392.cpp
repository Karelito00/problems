#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int i;
        cin>>i;
        long long y=2;
        if(i==0)
            break;
        if(i==1)
            cout<<0<<"\n";
        else if(i==2)
            cout<<0<<"\n";
            else {
                long long l=(i-y)*3;
                cout<<l*4<<"\n";
            }
    }
    return 0;
}
