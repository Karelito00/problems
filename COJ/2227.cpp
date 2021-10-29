#include <bits/stdc++.h>

using namespace std;
int mat[11][11];
int nmat[11][11];
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        string s;
        cin>>s;
        for(int j=0;j<a;j++){
            mat[i][j]=s[j]-'0';
        }
    }
    for(int y=1;y<a;y++){
        if(mat[0][y]>mat[0][y-1])
            nmat[0][y]=mat[0][y]-mat[0][y-1];
            nmat[0][y]+=nmat[0][y-1];
    }
    for(int k=1;k<a;k++){
        if(mat[k][0]>mat[k-1][0])
            nmat[k][0]=mat[k][0]-mat[k-1][0];
        nmat[k][0]+=nmat[k-1][0];
    }
    for(int i=1;i<a;i++){
        for(int j=1;j<a;j++){
            int u=0,l=0;
            if(mat[i][j]>mat[i-1][j])
                u=mat[i][j]-mat[i-1][j];
            if(mat[i][j]>mat[i][j-1])
                l=mat[i][j]-mat[i][j-1];
            nmat[i][j]=min(nmat[i-1][j]+u,nmat[i][j-1]+l);
        }
    }
    int y,x;
    cin>>y>>x;
    cout<<nmat[y-1][x-1];
    return 0;
}
