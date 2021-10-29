#include <bits/stdc++.h>
#define MAX 99999999
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)

using namespace std;

pair < int , int > arr[20];

int mat[21][21];
int dp[1<<16][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++){
        int n,m;
        cin>>n>>m;
        int con = 1;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin>>x;
                if(x == 'x'){
                    arr[0] = make_pair(i,j);
                }
                else if(x == 'g')
                    arr[con++] = make_pair(i,j), flag = true;
            }
        }
        if(!flag)
            con--;
        for(int i=0;i<con;i++){
            int y = arr[i].first, x = arr[i].second;
            for(int j=i+1;j<con;j++){
                int dist = mx(abs(y - arr[j].first), abs(x - arr[j].second));
                mat[i][j] = dist;
                mat[j][i] = dist;
            }
        }
        for(int i=0;i<(1<<con);i++){
            for(int j=0;j<con;j++)
                dp[i][j] = MAX;
        }
        dp[1][0] = 0;
        for(int mask=1;mask<(1<<con);mask++){
            for(int i=0;i<con;i++){
                if(mask&(1<<i)){
                   if(dp[mask][i] == MAX)
                        continue;;
                   for(int j=0;j<con;j++){
                        if(!(mask&(1<<j))){
                            dp[(mask|(1<<j))][j] = mn(dp[mask|(1<<j)][j], dp[mask][i] + mat[i][j]);
                        }
                    }
                }
            }
        }
        int best = MAX;
        for(int u=0;u<con;u++){
            if(dp[(1<<con)-1][u] != MAX)
                best = mn(best,dp[(1<<con)-1][u]+mat[0][u]);
        }
        if(con == 0) best = 0;
        cout<<"Case "<<l+1<<": "<<best<<"\n";
    }
    return 0;
}
