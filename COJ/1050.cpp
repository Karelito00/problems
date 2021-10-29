#include <bits/stdc++.h>

using namespace std;
bool karel(int p,int u){
int c=0;
for(int y=1;y<=u;y++){
    if(p%y==0 && u%y==0){
        c++;
    }
    if(c==2)
        return false;
}
if(c>=2){
return false;
}
else
    return true;
}
int main()
{
        int n;
        cin>>n;
        int suma=0;
        for(int k=1;k<n;k++){
          if(karel(k,n))
            suma++;
        }
        cout<<suma<<"\n";

    return 0;
        }
