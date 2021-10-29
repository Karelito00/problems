#include <bits/stdc++.h>

using namespace std;

int main()
{
    int o;
    cin>>o;
    for(int y=0;y<o;y++){
    double a;
    cin>>a;
    double b=(sqrt((a*a)+(a*a)))*(sqrt((a*a)+(a*a)));
    printf("%.2f",((acos(0)*2.0)*(a*a))-b);
    cout<<"\n";
    }
    return 0;
}