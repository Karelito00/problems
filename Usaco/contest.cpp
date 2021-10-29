#include <bits/stdc++.h>

using namespace std;
int mat[100][100];
void initializer(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=-1;

        }
    }
}
int main()
{
    freopen("contest.in","r",stdin);
    freopen("contest.out","w",stdout);
    int a,m;
    cin>>a>>m;
    initializer(a);
    for(int i=0;i<m;i++){
        int ady1,ady2;
        cin>>ady1>>ady2;
        ady1--;
        ady2--;
        mat[ady1][ady2]=1;
        mat[ady2][ady1]=0;
    }
    for(int k=0;k<a;k++){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(mat[i][k]==mat[k][j] && mat[i][k]!=-1){
                    mat[i][j]=mat[k][j];
                }
            }
        }
    }
    int con=0;
    for(int i=0;i<a;i++){
            int suma=0;
       for(int j=0;j<a;j++){
            if(mat[i][j]!=-1)
                suma++;
       }
        if(suma==a-1)
            con++;
    }
    cout<<con;
    return 0;
}
