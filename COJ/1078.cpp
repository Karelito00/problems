#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int a;
   cin>>a;
   for(int x=0;x<a;x++){
    int b,suma=0;
    cin>>b;
    for(int c=0;c<b;c++){
        int y;
        cin>>y;
        suma+=y;
        }
    if(suma%b==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";

   }
    return 0;
}