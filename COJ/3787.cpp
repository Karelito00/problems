#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[4][10005];
vector < int > v;
map < long long , int > q;

void prep(){
    dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 1;
    for(int i=1;i<=3;i++){
        for(int j = 1;j<10001;j++){
            for(int k = 0;k <= j;k++){
                dp[i][j] += dp[i - 1][j - k];
            }
            if(i == 3){
                if(q.find(dp[i][j]) != q.end())
                    q[dp[i][j]] = j;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        v.push_back(n);
        q.insert(make_pair(n,-1));
    }

    prep();

    for(int i=0;i<(int)v.size();i++){
        if(q[v[i]] != -1)
            cout<<q[v[i]]<<"\n";
        else
            cout<<"No solution\n";
    }
    return 0;
}

