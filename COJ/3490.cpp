#include <bits/stdc++.h>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        float c,d;
        cin>>c>>d;
        float k=d/c;
        cout<<d-k<<"\n";
    }
    return 0;
}
