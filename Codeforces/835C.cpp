#include <bits/stdc++.h>

using namespace std;

int n, q, c;
int brillo[13][150][150];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q>>c;
    c++;
    for(int i=0;i<n;i++){
        int x, y, s;
        cin>>x>>y>>s;
        brillo[s+1][x][y]++;
    }
    for(int k=1;k<=c;k++){
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                brillo[k][i][j] += brillo[k][i-1][j] + brillo[k][i][j-1] - brillo[k][i-1][j-1];
            }
        }
    }
    while(q--){
        long long t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        long long sol = 0;
        int ini = (t % c);
        for(int k=1;k<=c;k++,ini++){
            if(ini == c)
                ini = 0;
            sol += ini * (brillo[k][x2][y2] - brillo[k][x2][y1-1] - brillo[k][x1-1][y2] + brillo[k][x1-1][y1-1]);
        }
        cout<<sol<<"\n";
    }
    return 0;
}
