#include <bits/stdc++.h>

using namespace std;
int z[100000000];
int main()
{
    freopen("snotes.in","r",stdin);
    freopen("snotes.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    long long i=0;
    for(int j=0;j<n;j++){
        int h;
        cin>>h;
        for(int k=i;k<i+h;k++){
            z[k]=j+1;
        }
        i+=h;
    }
    for(int p=0;p<q;p++){
        int h;
        cin>>h;
        cout<<z[h]<<"\n";
    }
    return 0;
}
