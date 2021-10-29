#include <bits/stdc++.h>

using namespace std;

int z[100001];

int main()
{
    freopen("parcelas.in","r",stdin);
    freopen("parcelas.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >>n>>k;

    for(int i=0;i<n;i++)
        cin>>z[i];

    sort(z,z + n);
    int best = 0;
    for(int i=0;i<n;i++){
        int pos = lower_bound(z,z + n,z[i] - k) - z;
        best = max(best,i-pos);
    }
    cout<<best+1;

    return 0;
}
