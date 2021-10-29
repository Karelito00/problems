#include <bits/stdc++.h>

using namespace std;
int mat[101][101];
int main()
{
    vector < pair  <int,int> > lista;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
            int y,x;
            cin>>y>>x;
            mat[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            if(i*j==m)
                lista.push_back(make_pair(i,j));
        }
    }
    int best=99999999;
    for(int u=0;u<lista.size();u++){
        int y=lista[u].first,x=lista[u].second;
        for(int i=y;i<=n;i++){
            for(int j=x;j<=n;j++){
                int o=mat[i][j]-mat[i-y][j]-mat[i][j-x]+mat[i-y][j-x];
                best=min(best,m-o);
            }
        }
    }
    cout<<best;
    return 0;
}
