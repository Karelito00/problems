#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 5;

bool diag[MAXn][MAXn];
double mat[MAXn][MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>m>>n;
    int k;
    cin>>k;
    double cn = sqrt(20000);
    double nm = 100;
    for(int i = 1; i <= k; i++){
        int n1, n2;
        cin>>n2>>n1;
        diag[n1][n2] = true;
    }
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++) mat[i][j] = INT_MAX;
    }
    mat[1][1] = 0;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            mat[i + 1][j] = mn(mat[i][j] + nm, mat[i + 1][j]);
            mat[i][j + 1] = mn(mat[i][j] + nm, mat[i][j + 1]);
            if(diag[i][j])
                mat[i + 1][j + 1] = mn(mat[i][j] + cn, mat[i + 1][j + 1]);
        }
    }
    cout<<round(mat[n + 1][m + 1]);
    return 0;
}
