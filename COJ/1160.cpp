#include <bits/stdc++.h>

using namespace std;

bool comp(int x,int y){
    if(x == y)
        return true;
    if(x - 2 == y)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x == 0 && y == x){
            cout<<0<<"\n";
            continue;
        }
        if(x == 1 && y == x){
            cout<<1<<"\n";
            continue;
        }
        if(!comp(x,y))
            cout<<"No Number\n";
        else{
            if(x % 2 == 0)
                cout<<x+y<<"\n";
            else{
                cout<<x+y-1<<"\n";
            }
        }
    }
    return 0;
}
