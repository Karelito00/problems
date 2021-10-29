#include <iostream>
#include <cstdio>
using namespace std;
int main()
{   double a,b,c;
    cin>>a>>b>>c;
    double p=(a+b+c)/2;
    double A2=3.14159265358979*(((p-a)*(p-b)*(p-c)/p)+(a*a+b*b+c*c)/12);
    printf ("%.3f", A2);
    return 0;
}