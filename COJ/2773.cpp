#include <bits/stdc++.h>

using namespace std;
int suma[1000];
pair <int,int> best;
int main()
{
    int d1,d2,d3;
    scanf("%d %d %d",&d1,&d2,&d3);
    for(int i=1;i<=d1;i++){
        for(int j=1;j<=d2;j++){
            for(int k=1;k<=d3;k++){
                suma[i+j+k]++;
            }
        }
    }
    for(int h=0;h<=d1+d2+d3;h++){
        if(suma[h]>best.first){
            best.first=suma[h];
            best.second=h;
        }
    }
    printf("%d",best.second);
    return 0;
}

