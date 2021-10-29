#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int mat[251][251];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            mat[i][j] = INT_MAX;
        mat[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        mat[n1][n2] = mn(mat[n1][n2], w);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                mat[j][k] = mn(mat[j][k], mx(mat[j][i], mat[i][k]));
            }
        }
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<(mat[a][b] == INT_MAX ? -1 : mat[a][b])<<"\n";
    }
    return 0;
}
