#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i = 1; i <= n; i++){
      int a,c=0;
      cin>>a;
      while(a > 1){
        a = a/2;
        c++;
      }

      cout<<"Case #"<<i<<": "<<c<<"\n";
    }



 return 0;

}