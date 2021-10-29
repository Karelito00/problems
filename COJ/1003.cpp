#include <bits/stdc++.h>
using namespace std;
int z[10];
int main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);
int a,n,m,f;
cin>>a;
while(a--){
memset(z, 0, sizeof z);
cin>>n>>m;
for(int c=0;c<m;c++){
for(int g=0;g<n;g++){
cin>>f;
z[g]+=f;
}
}
//int sol = max_element(z, z + n) - z;
int x,p=-1;
for(int h=0;h<n;h++){
if(p<z[h]){
p=z[h];
x=h+1;
}
}
//cout<<x<<" "<<sol+1<<"\n";
 cout<<x<<"\n";
 }
//system("pause>nul");
return 0;
}