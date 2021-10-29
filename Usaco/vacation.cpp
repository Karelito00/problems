#include <bits/stdc++.h>
#define MAX 9999999

using namespace std;
typedef long long ll;
ll mat[200][200];
void initializer(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=MAX;
            if(i==j)
                mat[i][j]=0;
        }
    }
}
int main()
{
    freopen("vacation.in","r",stdin);
    freopen("vacation.out","w",stdout);
    int a,m,c,p;
    cin>>a>>m>>c>>p;
    initializer(a);
    for(int u=0;u<m;u++){
        int ady1,ady2,peso;
        cin>>ady1>>ady2>>peso;
        ady1--;
        ady2--;
        mat[ady1][ady2]=peso;
    }
    for(int k=0;k<a;k++){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(mat[i][k] + mat[k][j] < mat[i][j]){
                    mat[i][j]=mat[i][k] + mat[k][j];
                }
            }
        }
    }
    ll suma=0,con=0;
    for(int u=0;u<p;u++){
        int ans1,ans2;
        cin>>ans1>>ans2;
        ans1--;
        ans2--;
        ll minm=999999999;
        for(int i=0;i<c;i++){
            if(mat[ans1][i]!=MAX && mat[i][ans2]!=MAX && mat[ans1][i]+mat[i][ans2]<minm){
                minm=mat[ans1][i]+mat[i][ans2];
            }
        }
        if(minm!=999999999){
        suma+=minm;
        con++;
        }
    }
        cout<<con<<"\n"<<suma;
    return 0;
}
