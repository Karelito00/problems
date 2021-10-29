#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int sum1=0;
    for(int l=0;l<a;l++){
        int c;
        cin>>c;
        sum1+=c;
    }
    int sum2=0;
    for(int l=0;l<b;l++){
        int f;
        cin>>f;
        sum2+=f;
    }
    if(sum1>sum2)
        cout<<"first win";
    if(sum1<sum2)
        cout<<"second win";
        if(sum1==sum2)
        cout<<"tie";
    return 0;
}
