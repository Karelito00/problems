#include <bits/stdc++.h>

using namespace std;

int n, p;
int arr[13];
int cost[13];
int sol = 0;

void backtracking(int pos,int cash){
    if(cash == p){
        sol++;
        return;
    }
    if(pos > n)
        return;
    for(int i = 0; i <= arr[pos]; i++){
        if((cost[pos] * i) + cash <= p){
            backtracking(pos + 1, (cost[pos] * i) + cash);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    for(int j = 1; j <= n; j++){
        cin>>cost[j];
    }
    backtracking(1,0);
    cout<<sol;
    return 0;
}
