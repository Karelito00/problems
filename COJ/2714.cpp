#include <bits/stdc++.h>
#define ma 999999999

using namespace std;

long long mat[101][101];
void initializer(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=ma;
            if(i==j)
                mat[i][j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,m;
        cin>>n>>m;
        if(b>0)
            cout<<'\n';
        initializer(n);
        for(int k=0;k<m;k++){
            long long n1,n2,p;
            cin>>n1>>n2>>p;
            n1--,n2--;
            mat[n1][n2]=min(mat[n1][n2],p);
            mat[n2][n1]=min(mat[n2][n1],p);
        }
        int q;
        cin>>q;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                if(mat[i][k]<ma){
                    for(int j=0;j<n;j++){
                        if(mat[k][j]+mat[i][k]<mat[i][j])
                            mat[i][j]=mat[k][j]+mat[i][k];
                    }
                }
            }
        }
        for(int k=0;k<q;k++){
            int n1,n2;
            cin>>n1>>n2;
            n1--,n2--;
            if(mat[n1][n2]==ma)
                cout<<-1<<'\n';
            else
                cout<<mat[n1][n2]<<'\n';
        }
    }
    return 0;
}
