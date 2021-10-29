#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long a1=abs(a-b),a2=a+b-1;
    long long sumato=(a1*(a1+1))/2;
    long long sumato1=(a2*(a2+1))/2;
    printf("%lld",sumato1-sumato);
    return 0;
}
