#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long suma = 0;
    for(int i=1;i<=n;i++){
        int y;
        cin>>y;
        suma += y;
    }
    int q;
    cin>>q;
    long long best = 99999999;
    while(q--){
        long long l,r;
        cin>>l>>r;
        if(l>r) swap(l,r);
        if(suma <= r){
            if(suma < l)
                best = min(best,l);
            else
                best = min(best,suma);
        }
    }
    if(best == 99999999)
        cout<<-1;
    else
        cout<<best;
    return 0;
}
