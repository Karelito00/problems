#include <bits/stdc++.h>

using namespace std;

int posx[]={1,-1,0,0};
int posy[]={0,0,1,-1};
int mat[1001][1001];
int dist2[1001][1001];
bool dist21[1001][1001];
int y,x,best=99999999;
pair <int,int> ini,fin;

void bfs(){
    queue < pair <int,int> > cola;
    cola.push(ini);
    dist21[ini.first][ini.second]=1;
    mat[ini.first][ini.second]=0;
    mat[fin.first][fin.second]=0;
    while(!cola.empty()){
        int y1=cola.front().first;
        int x1=cola.front().second;
        cola.pop();
        for(int h=0;h<4;h++){
            int cy=posy[h],cx=posx[h];
            if(cy+y1>=0 && cy+y1<y && cx+x1<x && cx+x1>=0 && (mat[y1+cy][x1+cx]==0 || mat[y1+cy][x1+cx]==-4) && dist21[cy+y1][cx+x1]==false){
                cola.push(make_pair(cy+y1,cx+x1));
                dist2[cy+y1][cx+x1]=dist2[y1][x1]+1;
                dist21[cy+y1][cx+x1]=true;
            }
        }
    }
    cola.push(fin);
    while(!cola.empty()){
        int y1=cola.front().first;
        int x1=cola.front().second;
        cola.pop();
        for(int h=0;h<4;h++){
            int cy=posy[h],cx=posx[h];
            if(cy+y1>=0 && cy+y1<y && cx+x1<x && cx+x1>=0 && (mat[y1+cy][x1+cx]==0 || mat[y1+cy][x1+cx]==-4)){
                cola.push(make_pair(cy+y1,cx+x1));
                if(mat[y1+cy][x1+cx]==-4){
                    best=min(best,dist2[y1+cy][x1+cx]+mat[y1][x1]+1);
                }
                mat[cy+y1][cx+x1]=mat[y1][x1]+1;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&x,&y);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==2){
                ini.first=i,ini.second=j;
            }
            else if(mat[i][j]==3){
                fin.first=i,fin.second=j;
            }
            else if(mat[i][j]==1)
                mat[i][j]=-1;
            else if(mat[i][j]==4)
                mat[i][j]=-4;
        }
    }
    bfs();
    cout<<best;
    return 0;
}
