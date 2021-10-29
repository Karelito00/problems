#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    int con = 0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        if(x > b && x < c)
            con++;
    }
    cout<<con;
    return 0;
}
