#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int table[102][102][28];

int funt(int i, int j, int y, int x){
    int cant = 0;
    for(int k = 1; k <= 26; k++){
        int aux = table[y][x][k] - table[i - 1][x][k] - table[y][j - 1][k] + table[i - 1][j - 1][k];
        if(aux > 0) cant++;
    }
    return cant;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x;
            cin>>x;
            table[i][j][x - 'A' + 1]++;
        }
    }
    for(int k = 1; k <= 26; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                table[i][j][k] += table[i - 1][j][k] + table[i][j - 1][k] - table[i - 1][j - 1][k];
        }
    }
    int sol = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int y = i; y <= n; y++){
                for(int x = j; x <= m; x++){
                    if(funt(i, j, y, x) == k)
                        sol++;
                }
            }
        }
    }
    cout<<sol;
    return 0;
}
