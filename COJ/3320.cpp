#include <bits/stdc++.h>

using namespace std;

long long num[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int con = 0;
    for(long long i=1;i*i<=1000000000;i++){
        num[i] = i * i;
        con++;
    }
    while(1){
        long long a,b;
        cin>>a>>b;
        if(a == b && a == 0)
            return 0;
        long long n1 = upper_bound(num+1,num+con+1,b) - num - 1;
        long long n2 = lower_bound(num+1,num+con+1,a) - num - 1;
        long long suma = (a*(a-1))/2;
        long long sumb = (b*(b+1))/2;
        cout<<sumb - suma - (((n1*(n1+1)*(2*n1+1))/6) - ((n2*(n2+1)*(2*n2+1))/6))<<"\n";
    }
    return 0;
}
