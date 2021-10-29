#include <bits/stdc++.h>

using namespace std;
long long a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        long long num1=0,num2=0;
        num1=sqrt(a-1);
        num2=sqrt(b);
        cout<<(b-a+1)-(num2-num1)<<"\n";
    }
    return 0;
}
