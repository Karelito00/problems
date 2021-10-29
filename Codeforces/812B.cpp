#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)

using namespace std;

int mat[16][150];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    m += 2;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            mat[i][j] = x - '0';
        }
    }
    int pos = 0;
    for(int i = 1;i < m;i++){
        if(mat[0][i]==1)
            pos = i;
    }
    int best= 99999999;
    for(int mask = 0; mask < (1<<n); mask++){
        int p = pos;
        int suma = pos;
        int piso = 0;
        for(int i=0;i<n-1;i++){
            if(mask&(1<<i)){
                int newpos = 0;
                for(int j=1;j<m-1;j++){
                    if(mat[i+1][j]==1)
                        newpos = j;
                }
                if(newpos != 0){
                    suma += (p + (i + 1 - piso) + newpos);
                    p = newpos;
                    piso = i+1;;
                }
            }
            else{
                int newpos = 0;
                for(int j=m-1;j>=1;j--){
                    if(mat[i+1][j]==1)
                        newpos = j;
                }
                if(newpos != 0){
                    suma += ((m - p - 1) + (i + 1 -piso) + (m - newpos - 1));
                    p = newpos;
                    piso = i+1;
                }
            }
        }
        best = mn(best,suma);
    }
    cout<<best;
    return 0;
}
