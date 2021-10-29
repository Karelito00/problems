#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int posy[]={1,0,-1,0};
int posx[]={0,1,0,-1};
int main()
{
    freopen("lake.in","r",stdin);
    freopen("lake.out","w",stdout);
    int y,x,k;
    cin>>y>>x>>k;
    for(int n=0;n<k;n++){
        int y1,x1;
        cin>>y1>>x1;
        mat[y1-1][x1-1]='*';
    }
    int mayor=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='*'){
            int cant=1;
            mat[i][j]='.';
            queue < pair <int,int> > cola;
            cola.push(make_pair(i,j));
            while(!cola.empty()){
                pair <int,int> v=cola.front();
                cola.pop();
                for(int u=0;u<4;u++){
                    int cy=v.first,cx=v.second;
                    if(cy+posy[u]>=0 && cy+posy[u]<y && cx+posx[u]>=0 && cx+posx[u]<x && mat[cy+posy[u]][cx+posx[u]]=='*'){
                        mat[cy+posy[u]][cx+posx[u]]='.';
                        cant++;
                        cola.push(make_pair(cy+posy[u],cx+posx[u]));
                    }
                }
            }
            if(cant>mayor)
                mayor=cant;
            }
    }
    }
    cout<<mayor;
    return 0;
}
