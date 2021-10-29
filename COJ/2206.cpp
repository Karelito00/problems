#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cp;
    scanf("%d", &cp);
    while (cp-->0){
        double r,p,q;
        scanf("%lf%lf%lf", &r, &p, &q);
        double ang=abs(p-q);
        double rad=(ang*acos(0))/90;
        double t=r*r*abs(sin(rad))/2;
        if (ang<=180){
                double sc=((4*acos(0)-rad))*r*r/2;
                double A=sc+t;
                printf ("%.3f\n", A);
        }
        if (ang>180){
                double sc=(rad)*r*r/2;
                double A=sc+t;
                printf ("%.3f\n", A);
        }
    }
    return 0;
}