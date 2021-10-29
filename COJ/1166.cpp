#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int a;
   cin>>a;
   for(int b=0;b<a;b++){
    int c,p=0,i=0;
    cin>>c;
    for(int h=0;h<c;h++){
        int d;
        cin>>d;
        if(d%2==0)
            p++;
        else if(d%2!=0)
           i++;
    }
    cout<<p<<" even and "<<i<<" odd.\n";
   }
    return 0;
}
