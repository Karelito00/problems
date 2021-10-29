#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a;
    int b;
     cin>>a>>b;
    if(b==1)
        printf("%.1f",a);
    if(b==2)
        printf("%.2f",a);
    if(b==3)
        printf("%.3f",a);
    if(b==4)
        printf("%.4f",a);
    if(b==5)
        printf("%.5f",a);
    if(b==6)
        printf("%.6f",a);
    return 0;
}
