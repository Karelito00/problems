#include <bits/stdc++.h>

using namespace std;
int f1[21];
int m1[21];
pair <float,int> best;
int main()
{
    int f,m,a;
    scanf("%d%d%d",&f,&m,&a);
    for(int i=0;i<a;i++){
        scanf("%d %d",&f1[i],&m1[i]);
    }
    for(int mask=0;mask<(1<<a);mask++){
            int sumaf=f,sumam=m;
        for(int k=0;k<a;k++){
            if(mask&(1<<k)){
                sumaf+=f1[k];
                sumam+=m1[k];
            }
        }
        if((float)sumaf/(float)sumam>best.first){
            best.first=(float)sumaf/(float)sumam;
            best.second=mask;
        }
    }
    if(__builtin_popcount(best.second)==0)
        printf("NONE");
    else{
        for(int i=0;i<a;i++){
            if(best.second&(1<<i))
                printf("%d\n",i+1);
        }
    }
    return 0;
}
