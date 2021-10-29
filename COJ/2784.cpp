#include <bits/stdc++.h>

using namespace std;
int z[10000];
int main()
{
    int a,h=0;
    cin>>a;
    for(int b=0;b<a;b++){
        int c;
        cin>>c;
        z[b]=c;
        if(c>h)
            h=c;
    }
    int f;
    cout<<h<<" ";
    for(int x=0;x<a-1;x++){
    for(int j=x+1;j<a;j++){
        if(z[x]<z[j]){
         f=z[x];
         z[x]=z[j];
         z[j]=f;
}
}
}
for(int k=a-1;k>=1;k--){
    cout<<z[k]<<" ";
}


    return 0;
}
