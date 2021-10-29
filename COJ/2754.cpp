#include <bits/stdc++.h>
#define MAX 999999999
#define mn(a,b) (a < b ? a : b)

using namespace std;

int dp[(1<<16)+1];
vector < int > pal;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        int l = s.size();
        for(int i=0;i<(1<<l)-1;i++)
            dp[i] = MAX;
        dp[(1<<l)-1] = 0;
        for(int ma=1;ma<(1<<l);ma++){
            string t;
            for(int i=0;i<l;i++){
                if(ma&(1<<i))
                    t.push_back(s[i]);
            }
            string k = t;
            reverse(t.begin(),t.end());
            if(k == t)
                pal.push_back(ma);
        }
        for(int mask=(1<<l)-1;mask>0;mask--){
            for(int i=0;i<(int)pal.size();i++){
                if(pal[i]>mask)
                    break;
                if((mask | pal[i]) == mask)
                    dp[mask^pal[i]] = mn(dp[mask^pal[i]],dp[mask]+1);
            }
        }
        cout<<dp[0]<<"\n";
        pal.clear();
    }
    return 0;
}
