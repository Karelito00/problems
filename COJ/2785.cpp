#include <bits/stdc++.h>
using namespace std;
int main()
{
float a,sum=0;
cin>>a;
for(int b=0;b<a;b++){
    float y;
    cin>>y;
    sum+=y;
}
printf("%.2f",sum/a);

    return 0;
}
