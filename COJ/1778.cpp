#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        float a,b;
        cin>>a>>b;
        float area=((b*a/2)/2)-((b/2*a/4)/2);
        printf("%.8f\n",area);
    }
    return 0;
}
