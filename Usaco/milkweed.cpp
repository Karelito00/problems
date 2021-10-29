#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int posy[]={0,1,-1,0,1,-1,1,-1};
int posx[]={1,0,0,-1,1,-1,-1,1};
int z[100][100];
int main()
{
    freopen("milkweed.in","r",stdin);
    freopen("milkweed.out","w",stdout);
    int x,y,cy,cx;
    cin>>x>>y>>cx>>cy;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
        }
    }
    queue < pair <int,int> > cola;
    cola.push(make_pair(y-cy,cx-1));
    z[y-cy][cx-1]=0;
    int ma=0;
    while(!cola.empty()){
        pair <int,int> v=cola.front();
        cola.pop();
        if(z[v.first][v.second]>ma)
            ma=z[v.first][v.second];
        for(int h=0;h<8;h++){
            int c1y=v.first,c1x=v.second;
            if(c1y+posy[h]>=0 && c1y+posy[h]<y && c1x+posx[h]>=0 && c1x+posx[h]<x && mat[c1y+posy[h]][c1x+posx[h]]=='.'){
                z[c1y+posy[h]][c1x+posx[h]]=z[c1y][c1x]+1;
                mat[c1y+posy[h]][c1x+posx[h]]='*';
                cola.push(make_pair(c1y+posy[h],c1x+posx[h]));
            }
        }
    }
    cout<<ma;
    return 0;
}
