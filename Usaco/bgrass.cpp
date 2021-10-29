#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int posy[]={1,0,-1,0};
int posx[]={0,1,0,-1};
int main()
{
    freopen("bgrass.in","r",stdin);
    freopen("bgrass.out","w",stdout);
    int y,x;
    cin>>y>>x;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++)
            cin>>mat[i][j];
    }
    int cant=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='#'){
                cant++;
                queue < pair <int,int> > cola;
                cola.push(make_pair(i,j));
                mat[i][j]='.';
                while(!cola.empty()){
                    pair <int,int> v=cola.front();
                    cola.pop();
                    for(int u=0;u<4;u++){
                        int cy=v.first,cx=v.second;
                        if(cy+posy[u]>=0 && cy+posy[u]<y && cx+posx[u]>=0 && cx+posx[u]<x && mat[cy+posy[u]][cx+posx[u]]=='#'){
                            cola.push(make_pair(cy+posy[u],cx+posx[u]));
                            mat[cy+posy[u]][cx+posx[u]]='.';
                        }
                    }
                }
            }
        }
    }
    cout<<cant;
    return 0;
}
