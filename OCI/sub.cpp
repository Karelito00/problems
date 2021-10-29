#include <bits/stdc++.h>

using namespace std;

struct par{
    int cant;
    int pos;
};
int z[2001];
par dp[2001];

int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    /* Catcher */
    pair <int,int> best;
    for(int i=0;i<n;i++){
        dp[i].pos=i;
        for(int j=0;j<i;j++){
            if(z[i]%z[j]==0){
                if(dp[i].cant < dp[j].cant + 1){
                    dp[i].cant = dp[j].cant + 1;
                    dp[i].pos = j;
                }
            }
        }
        if(best.first < dp[i].cant){
            best.first = dp[i].cant;
            best.second = i;
        }
    }
    vector <int> arr;
    cout<<best.first+1<<"\n";
    int x=best.second;
    while(x != dp[x].pos){
        arr.push_back(z[x]);
        x = dp[x].pos;
    }
    arr.push_back(z[x]);
    reverse(arr.begin(),arr.end());
    for(auto x: arr){
        cout<<x<<"\n";
    }
    return 0;
}
