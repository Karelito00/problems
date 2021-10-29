#include <iostream>
#include <algorithm>

using namespace std;
int z[20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>z[j];
        }
        sort(z,z+k);
        int suma=z[k-1]-z[0];
        for(int n=1;n<k;n++){
            suma+=(z[n]-z[n-1]);
        }
        cout<<suma<<"\n";
    }
    return 0;
}
