#include <bits/stdc++.h>

using namespace std;
int z[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin>>i;
    for(int p=0;p<i;p++){
    int a,b;
    cin>>a>>b;
    for(int y=0;y<b;y++){
        int h;
        cin>>z[y]>>h;
    }
    sort(z,z+b);
    long long sum=0;
    b-=1;
   while(a--){
    sum+=z[b];
    b--;
   }
   cout<<sum<<"\n";
    }
    return 0;
}
