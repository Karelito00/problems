#include <bits/stdc++.h>
#define MAX 9999999
using namespace std;
int z[10000];
int mat[1000][1000];
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
    freopen("bestspot.in","r",stdin);
    freopen("bestspot.out","w",stdout);
    int a,f,c;
    cin>>a>>f>>c;
    for(int i=0;i<f;i++){
        cin>>z[i];
        z[i]--;
    }
    initializer(a);
    for(int k=0;k<c;k++){
        int ady1,ady2,peso;
        cin>>ady1>>ady2>>peso;
        ady1--;
        ady2--;
        mat[ady1][ady2]=peso;
        mat[ady2][ady1]=peso;
    }
    for(int k=0;k<a;k++){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(mat[i][j] > mat[i][k] + mat[k][j]){
                    mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
    }
    int nodo=0;
    float mayor=MAX;
    for(int i=0;i<a;i++){
            float suma=0;
        for(int j=0;j<f;j++){
            if(mat[i][z[j]]!=MAX){
                suma+=mat[i][z[j]];
            }
        }
            suma/=f;
            if(suma<mayor){
                mayor=suma;
                nodo=i+1;
            }
    }
    cout<<nodo;
    return 0;
}
