#include <bits/stdc++.h>

using namespace std;

int a,m;
int costo[2501];
int dp[2501];
int main(){
    cin>>a>>m;
    costo[0]=m;
    for(int y=1;y<=a;y++){
        cin>>costo[y];
        costo[y]+=costo[y-1];
    }
    for(int i = 1; i <= a; i++){
        dp[i] = costo[i];
    for(int j = 0; j <= i; j++){
       dp[i]=min(dp[j]+dp[i-j]+costo[0], dp[i]);
    }
    }
    cout<<dp[a];
    return 0;
}
