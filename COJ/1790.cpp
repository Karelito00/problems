#include <bits/stdc++.h>

using namespace std;
int z[10001];
int main()
{
    int a,con=-1;
    cin>>a;
    for(int i=0;i<a;i++){
        int p;
        cin>>p;
        z[i]=p;
            }
            int p=0,m=z[0];
            for(int j=0;j<a;j++){
                if(z[j]>p){
                    p=z[j];
                    con++;
                }
                if(z[j]<m && z[j]<p){
                    m=z[j];
                    con++;
                }
            }
cout<<con;

    return 0;
}