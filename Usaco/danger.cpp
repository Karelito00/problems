#include <bits/stdc++.h>

using namespace std;
int z[10000];
int mat[100][100];
int main()
{
    freopen("danger.in","r",stdin);
    freopen("danger.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>z[i];
        z[i]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
    int suma=0;
    for(int i=1;i<m;i++){
        suma+=mat[z[i-1]][z[i]];
    }
    cout<<suma;
    return 0;
}
