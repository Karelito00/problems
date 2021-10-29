#include <bits/stdc++.h>

using namespace std;
int z[100];
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF){
        memset(z,0,sizeof z);
        int sum=0,con=0;
        for(int b=0;b<a;b++){
            int m;
            cin>>m;
            sum+=m;
            z[b]=m;
        }
        for(int y=0;y<a;y++){
           if((sum-z[y])%2==0){
            con++;
           }

        }

        cout<<con<<"\n";

    }

    return 0;
}
