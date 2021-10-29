#include <bits/stdc++.h>

using namespace std;

int const MAXn = 5020;

int dp[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        string s;
        cin>>s;
        if(s == "0")
            break;
        s = " " + s;
        int tam = s.size();
        dp[0] = 1;
        for(int i = 1; i < tam; i++){
            if(s[i] != '0')
                dp[i] = dp[i - 1];
            if(i > 1){
                if((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6'))
                    dp[i] += dp[i - 2];
            }
        }
        cout<<dp[tam - 1]<<"\n";
        fill(dp, dp + tam + 5, 0);
    }
    return 0;
}
