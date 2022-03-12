#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int const MAXn = 1e5 + 2;

ll arr[MAXn];
ll dp[MAXn][3];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>arr[i];

    }

    for(int i = 2; i <= n + 1; i++) {
        ll change = 0, x = 0, y = 0;
        for(int l = 0; l < 30; l++) {
            bool k1 = arr[i - 2] & (1 << l);
            bool k2 = arr[i] & (1 << l);
            if(!k1 && !k2) 
                change += (1 << l);
        }
        ll sum = 0;
        if(i - 2 > 0)
            sum += arr[i - 2] ^ change;
        if(i <= n)
            sum += arr[i] ^ change;

        ll sumx = 0;
        if(i <= n)
            sumx += arr[i] ^ arr[i - 1];
        dp[i][0] = dp[i - 1][0] + sumx;

        dp[i][1] = dp[i - 1][1] + sumx;
        dp[i][1] = max(dp[i][1], dp[i - 2][0] + sum);

        dp[i][2] = dp[i - 1][2] + sumx;
        dp[i][2] = max(dp[i][2], dp[i - 2][1] + sum);


        if(i > 2) {
            for(int l = 0; l < 30; l++) {
                bool k1 = arr[i - 3] & (1 << l);
                bool k2 = arr[i] & (1 << l);
                if(!k1 && !k2) 
                    x += (1 << l);
                if(k1 && !k2)
                    y += (1 << l);
                if(k2 && !k1)
                    x += (1 << l);
            }
            ll sum = (x ^ y);
            if(i - 3 > 0)
                sum += x ^ arr[i - 3];
            if(i <= n)
                sum += y ^ arr[i];

            dp[i][2] = max(dp[i][2], dp[i - 3][0] + sum);
        }
    }
    cout<<max(dp[n + 1][0], max(dp[n + 1][1], dp[n + 1][2]))<<"\n";

    return 0;
}
