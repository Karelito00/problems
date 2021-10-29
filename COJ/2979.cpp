#include <bits/stdc++.h>

using namespace std;
int z[55];
int h[55];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int g,c=0;
        cin>>g;
        for(int i=0;i<g;i++){
            int n;
            cin>>n;
            z[i]=n;
            h[i]=n;
        }
        sort(z,z+g);
        for(int j=0;j<g;j++){
            if(z[j]!=h[j])
                c++;
        }
        cout<<c<<"\n";
        }
    return 0;
}
