#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int suma = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if((n/i)%k!=0)
                    suma += n/i;
                if(n/i!=i){
                    if(i%k!=0)
                        suma += i;
                }
            }
        }
        cout<<suma<<"\n";
    }
    return 0;
}
