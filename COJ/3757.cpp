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
        int n;
        cin>>n;
        int imp=0,par=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                (i%2==0 ? par++ : imp++);
                if(n/i!=i)
                    ((n/i)%2==0 ? par++ : imp++);
            }
        }
        cout<<"P: "<<par<<" I: "<<imp<<"\n";
    }
    return 0;
}
