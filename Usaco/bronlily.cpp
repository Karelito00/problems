#include <bits/stdc++.h>
#define MAX 30
using namespace std;
int mat[MAX][MAX];
int main()
{
    freopen("bronlily.in","r",stdin);
    freopen("bronlily.out","w",stdout);
    int y,x,m1,m2;
    cin>>y>>x>>m1>>m2;
    int iniy=0,inix=0,finy=0,finx=0;
    int posy[]={m1,m1*(-1),m1*(-1),m1,m2,m2*(-1),m2,m2*(-1)};
    int posx[]={m2,m2*(-1),m2,m2*(-1),m1,m1*(-1),m1*(-1),m1};
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
            if(mat[i][j]==3){
                inix=j;
                iniy=i;
            }
            if(mat[i][j]==4){
                finx=j;
                finy=i;
            }
        }
    }
    mat[iniy][inix]=0;
    mat[finy][finx]=1;
    queue < pair <int,int> > cola;
    cola.push(make_pair(iniy,inix));
    while(!cola.empty()){
        pair <int,int> v=cola.front();
        cola.pop();
        for(int u=0;u<8;u++){
            int cy=v.first,cx=v.second;
            if(cy+posy[u]>=0 && cy+posy[u]<y && cx+posx[u]>=0 && cx+posx[u]<x && mat[cy+posy[u]][cx+posx[u]]==1){
                cola.push(make_pair(cy+posy[u],cx+posx[u]));
                mat[cy+posy[u]][cx+posx[u]]=mat[cy][cx]+1;
            }
        }
    }
    cout<<mat[finy][finx];
    return 0;
}
