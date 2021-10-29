#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        double xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        double xc=xa+xb,yc=ya+yb;
        double m1=xa*yb,m2=xb*yc,m3=xc*ya,m4=xb*ya,m5=xc*yb,m6=xa*yc;
        double i=(m1+m2+m3)-(m4+m5+m6);
if(i<0)
i*=-1;
    printf("%.1f\n",i/2);
    }
    return 0;
}