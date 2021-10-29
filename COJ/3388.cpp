#include <bits/stdc++.h>

using namespace std;
int z[1000];
int main()

{
    //freopen("entr.in","r",stdin);
    //freopen("salid.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    int x=0;
    while(a>0){
    int c=0;
  int u=a;
  while(u>0){
    int b;
    b=u%10;
    u=u/10;
    z[c]=b;
    c++;
  }
  sort(z,z+c);
  x++;
  int o=z[0];
  for(int y=1;y<c;y++){
    o=o*10+z[y];
  }
a=a-o;
}
cout<<x;
    return 0;
}
