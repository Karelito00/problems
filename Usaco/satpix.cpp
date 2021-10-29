#include <bits/stdc++.h>

using namespace std;
char mat[1000][1000];
int posy[]={1,0,-1,0};
int posx[]={0,1,0,-1};
int main()
{
    freopen("satpix.in","r",stdin);
    freopen("satpix.out","w",stdout);
    int y,x;
    cin>>x>>y;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++)
            cin>>mat[i][j];
    }
    int may=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='*'){
                queue < pair <int,int> > cola;
                int con=1;
                cola.push(make_pair(i,j));
                mat[i][j]='.';
                while(!cola.empty()){
                    pair <int,int> v=cola.front();
                    cola.pop();
                    for(int l=0;l<4;l++){
                        int cy=v.first,cx=v.second;
                        if(cy+posy[l]>=0 && cy+posy[l]<y && cx+posx[l]>=0 && cx+posx[l]<x && mat[cy+posy[l]][cx+posx[l]]=='*'){
                            cola.push(make_pair(cy+posy[l],cx+posx[l]));
                            mat[cy+posy[l]][cx+posx[l]]='.';
                            con++;
                        }
                    }
                }
                if(con>may)
                    may=con;
            }
        }
    }
    cout<<may;
    return 0;
}
