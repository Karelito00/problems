#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n;
        cin>>n;
        long long suma=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                suma+=n/i;
                suma+=i;
                if(n/i==i)
                    suma-=i;
            }
        }
        suma-=n;
        cout<<suma<<"\n";
    }
    return 0;
}
