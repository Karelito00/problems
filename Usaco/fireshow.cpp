#include <bits/stdc++.h>

using namespace std;
bool fire[2000000];
int main()
{
    freopen("fireshow.in","r",stdin);
    freopen("fireshow.out","w",stdout);
    int c,n;
    cin>>c>>n;
    int suma=0;
    for(int i=0;i<c;i++){
        int k;
        cin>>k;
        int t=k;
        while(k<=n){
          if(fire[k]==false){
          suma++;
          fire[k]=true;
        }
        k+=t;
        }
    }
    cout<<suma;
    return 0;
}
