#include <bits/stdc++.h>

using namespace std;

int a,b,a1,b1,car,lech,bas;

int mordidas(int traba){
    int con=0,mord=0;
for(int j=0;j<=traba;j++){
            int romp=0;
        if(con==0){
            for(int y=1;y<=a;y++){
                j++;
                if(j==traba){
                   romp++;
                   mord++;
                   break;
                }
            }
        }else{
            for(int u=1;u<=b;u++){
                j++;
                if(j==traba){
                    romp++;
                    break;
                }
            }
            }
        if(romp==1)
            break;
            con++;
            if(con==2)
                con=0;
                j--;
    }
    con=0;
    for(int j=0;j<=traba;j++){
            int romp=0;
        if(con==0){
            for(int y=1;y<=a1;y++){
                j++;
                if(j==traba){
                   romp++;
                   mord++;
                   break;
                }
            }
        }else{
            for(int u=1;u<=b1;u++){
                j++;
                if(j==traba){
                    romp++;
                    break;
                }
            }
            }
        if(romp==1)
            break;
            con++;
            if(con==2)
                con=0;
                j--;
    }
    return mord;
}

int main()
{
    scanf("%d %d %d %d %d %d %d",&a ,&b ,&a1 ,&b1, &car ,&lech, &bas);
    if(mordidas(car)==0)
        printf("none\n");
    else if(mordidas(car)==1)
        printf("one\n");
    else if(mordidas(car)==2)
        printf("both\n");
    if(mordidas(lech)==0)
        printf("none\n");
    else if(mordidas(lech)==1)
        printf("one\n");
    else if(mordidas(lech)==2)
        printf("both\n");
        if(mordidas(bas)==0)
        printf("none\n");
    else if(mordidas(bas)==1)
        printf("one\n");
    else if(mordidas(bas)==2)
        printf("both\n");
    return 0;
}
