#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int c,d;
        cin>>c>>d;
        ll suma=0;
        for(int o=c;o<=d;o++){
                ll n=1;
            for(int k=o;k<o+3;k++){
                n*=k;
            }
        suma+=n;
        }
        cout<<suma%100<<"\n";
    }
    return 0;
}
