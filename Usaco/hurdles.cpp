#include <bits/stdc++.h>
#define MAX 9999999
using namespace std;
int a,m,t;
int mat[300][300];
void formatriz(){
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            mat[i][j]=MAX;
            if(i==j)
                mat[i][j]=0;
        }
    }
}
int main()
{
    freopen("hurdles.in","r",stdin);
    freopen("hurdles.out","w",stdout);
    cin>>a>>m>>t;
    formatriz();
    for(int i=0;i<m;i++){
        int nod1,nod2,w;
        cin>>nod1>>nod2>>w;
        nod1--;
        nod2--;
        mat[nod1][nod2]=w;
    }
    for(int k=0;k<a;k++){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                mat[i][j]= min(mat[i][j] , max(mat[i][k],mat[k][j]) );
            }
        }
    }
    for(int h=0;h<t;h++){
        int t1,t2;
        cin>>t1>>t2;
        if(mat[t1-1][t2-1]==MAX)
            cout<<-1<<endl;
        else
            cout<<mat[t1-1][t2-1]<<endl;
    }
    return 0;
}
