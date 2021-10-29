#include <bits/stdc++.h>

using namespace std;

int mat[51][51];
int n, m;
long long pw[60];

long long funt1(int y, int num){
    long long con = 0;
    for(int i = 0; i < m; i++)
        if(mat[y][i] == num) con++;
    return con;
}
long long funt2(int x, int num){
    long long con = 0;
    for(int i = 0; i < n; i++)
        if(mat[i][x] == num) con++;
    return con;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }
    pw[0] = 1;
    for(int i = 1; i < 52; i++)
        pw[i] = pw[i - 1] * 2;
    long long sol = 0;
    for(int i = 0; i < n; i++){
        long long cant = funt1(i,1);
        sol += pw[cant] - 1;
    }
    for(int i = 0; i < m; i++){
        long long cant = funt2(i,1);
        sol += (pw[cant] - 1) - cant;
    }
    for(int i = 0; i < n; i++){
        long long cant = funt1(i,0);
        sol += pw[cant] - 1;
    }
    for(int i = 0; i < m; i++){
        long long cant = funt2(i,0);
        sol += (pw[cant] - 1) - cant;
    }
    cout<<sol;
    return 0;
}
