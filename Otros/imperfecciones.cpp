#include <bits/stdc++.h>

using namespace std;

long long criba[10000001];

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    long long suma=0;
    if(a==1){
        a++;
        suma++;
    }
    for(int y=2;y<b;y++){
        for(int h=y+y;h<=b;h+=y){
            criba[h]+=y;
        }
    }
    for(int i=a;i<=b;i++){
        suma+=abs(i-criba[i]-1);
    }
    printf("%lld",suma);
    return 0;
}
