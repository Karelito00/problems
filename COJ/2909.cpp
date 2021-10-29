#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int c=0;c<a;c++){
        int j;
        cin>>j;
        int n,m=-1;
        for(int u=1;u<=j;u++){
                int suma=0;
        for(int k=1;k<=u;k++){
            if(u%k==0)
            suma++;
        }
        if(suma>m){
            m=suma;
            n=u;
        }
        }
        cout<<n<<"\n";

    }
    return 0;
}
