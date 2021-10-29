#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MOD = 1e9 + 7;

long long mat[51][51];
long long mat2[51][51];
long long mataux[51][51];
int n, m;

void mult1(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++)
                mataux[i][j] = (mataux[i][j] + (mat[i][k] * mat2[k][j] % MOD)) % MOD;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mat[i][j] = mataux[i][j];
            mataux[i][j] = 0;
        }
    }
}

void mult2(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++)
                mataux[i][j] = (mataux[i][j] + (mat2[i][k] * mat2[k][j] % MOD)) % MOD;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mat2[i][j] = mataux[i][j];
            mataux[i][j] = 0;
        }
    }
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int n1, n2;
        cin>>n1>>n2;
        mat[n1][n2]++;
        mat2[n1][n2]++;
    }
    int q;
    cin>>q;
    q--;
    while(q >= 1){
        if(q&1){
            mult1();
            q--;
        }
        mult2();
        q /= 2;
    }
    cout<<mat[1][n];
    return 0;
}
