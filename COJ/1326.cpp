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
        long long suma;
        cin>>suma;
        int h;
        cin>>h;
        for(int j=0;j<h;j++){
            char l;
            int k;
            cin>>l>>k;
            if(l=='D'){
               suma-=k;
            }else{
               suma+=k;
            }
        }
        cout<<suma<<"\n";
    }
    return 0;
}
