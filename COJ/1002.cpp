#include <bits/stdc++.h>

using namespace std;
int mat[100][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                char s;
                cin>>s;
                if(s=='.')
                    mat[i][j]=1;
                else
                    mat[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
        int mayor=0,num=0;
        for(int p=1;p<=n;p++){
            for(int i=p;i<=n;i++){
                for(int j=p;j<=n;j++){
                    int suma=mat[i][j]-mat[i-p][j]-mat[i][j-p]+mat[i-p][j-p];
                    if(suma==p*p && suma>mayor){
                        mayor=suma;
                        num=p;
                    }
                }
            }
        }
        cout<<num<<"\n";
    }
    return 0;
}
/*
1
5
##..#
....#
.#..#
####.
.#..#
*/
