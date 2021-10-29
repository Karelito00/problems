#include <bits/stdc++.h>

using namespace std;
int divy[6000];
int divx[6000];
int main()
{
    int y,x;
    scanf("%d%d",&y,&x);
    int cony=0,conx=0;
    for(int i=1;i*i<=y;i++){
        if(y%i==0){
            if(y/i!=i){
                divy[cony]=y/i;
                cony++;
                divy[cony]=i;
                cony++;
            }
            else{
                divy[cony]=i;
                cony++;
            }
        }
    }
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(x/i!=i){
                divx[conx]=x/i;
                conx++;
                divx[conx]=i;
                conx++;
            }
            else{
                divx[conx]=i;
                conx++;
            }
        }
    }
    sort(divy,divy+cony);
    sort(divx,divx+conx);
    for(int u=0;u<cony;u++){
        for(int i=0;i<conx;i++){
            printf("%d %d\n",divy[u],divx[i]);
        }
    }
    return 0;
}
