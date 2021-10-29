#include <bits/stdc++.h>

using namespace std;

long long z[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>z[i];
        }
        long long p;
        cin>>p;
        sort(z,z+n);
        bool flag = false;
        for(int u=0;u<n;u++){
            for(int i=u+1;i<n;i++){
                long long suma = z[u] + z[i];
                if(suma > p)
                    break;
                int pos = lower_bound(z,z+n,p-suma) - z;
                if(pos != u && pos != i && pos < n && z[pos] == p - suma){
                    flag =true;
                    break;
                }
                else if(pos < n && z[pos] == p - suma){
                    for(int j=pos+1;j<n;j++){
                        if(z[j] != z[j-1])
                            break;
                        if(j != u && j!=i){
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
            }
            if(flag)
            break;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
