#include <bits/stdc++.h>

using namespace std;

int z[2000];

int main()
{
    int a;
    scanf("%d",&a);
    for(int b=0;b<a;b++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&z[i]);
        }
        int con=0;
        bool a1=false,a2=false;
        if(z[1]-z[0]==-1 || z[1]-z[0]==n-1){
            a1=1;
        }
        if(z[n-1]-z[n-1]==-1 || z[n-1]-z[n-2]==n-1){
            a2=1;
        }
        bool karel=false;
        if(a1== false && a2==false){
            if(z[0]-z[n-1]==n-1 || z[0]-z[n-1]==-1){
                karel=true;
                con+=2;
            }
        }
        if(karel==true){
            for(int i=2;i<n-1;i++){
                if(z[i]-z[i-1]==-1 || z[i]-z[i-1]==n-1){
                    con+=2;
                    i++;
                }
            }
        }else{
            for(int i=1;i<n;i++){
                if(z[i]-z[i-1]==-1 || z[i]-z[i-1]==n-1){
                    con+=2;
                    i++;
                }
            }
        }
        printf("%d\n",con);
    }
    return 0;
}
