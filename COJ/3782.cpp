#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        bool flag = false;
        int m = 1;
        for(int j=0;j<5;j++){
            int o;
            cin>>o;
            if(j >= 1 && o-1!=m){
                flag = true;
            }
            m = o;
        }
        if(!flag)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}

