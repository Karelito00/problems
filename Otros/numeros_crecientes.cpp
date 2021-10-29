#include <bits/stdc++.h>

using namespace std;

int n;
long long z[100001];
bool flag[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i];
    }
    sort(z+1,z+n+1);
    for(int i=1;i<=n;i++){
        z[i]+=z[i-1];
    }
    int con=0;
    flag[1]=true;
    for(int i=1;i<=n-1;i++){
        long long num=(z[i]-z[i-1])*2;
        if(!flag[i])
            num+=z[i-1]*2;
        if(num>=z[i+1]-z[i]){
            con++;
            flag[i]=true;
        }
        else
            con=0;
    }
    cout<<con+1;
    return 0;
}