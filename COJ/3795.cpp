#include <bits/stdc++.h>

using namespace std;

int criba[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=1000;i++)
        for(int y=i+i;y<=1000;y+=i)
            criba[y]+=i;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(criba[n]<n)
            cout<<"deficient\n";
        else if(criba[n] == n)
            cout<<"perfect\n";
        else
            cout<<"abundant\n";
    }
    return 0;
}
