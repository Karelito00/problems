#include <bits/stdc++.h>

using namespace std;
int mat[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
            if(mat[i][j]<0)
                mat[i][j]=0;
            mat[i][j]+=(mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]);
        }
    }
    for(int y=0;y<q;y++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<mat[y2][x2]-mat[y2][x1-1]-mat[y1-1][x2]+mat[y1-1][x1-1]<<"\n";
    }
    return 0;
}
