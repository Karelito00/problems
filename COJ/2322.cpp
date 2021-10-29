#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int s;
        cin>>s;
        int suma=1;
        for(int y=0;y<s;y++){
            int o;
            cin>>o;
            suma+=o-1;
        }
        cout<<suma<<"\n";
    }
    return 0;
}
