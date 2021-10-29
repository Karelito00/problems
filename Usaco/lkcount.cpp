#include <bits/stdc++.h>

using namespace std;
char mat[750][750];
int posy[]={1,0,0,-1,1,-1,1,-1};
int posx[]={0,1,-1,0,1,-1,-1,1};
int main(){
    freopen("lkcount.in","r",stdin);
    freopen("lkcount.out","w",stdout);
    int y,x;;
    cin>>y>>x;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
        }
    }
    int con=0;
    queue < pair <int,int> > cola;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='W'){
                con++;
                mat[i][j]='.';
                cola.push(make_pair(i,j));
                while(!cola.empty()){
                    int cy=cola.front().first,cx=cola.front().second;
                    cola.pop();
                    for(int h=0;h<8;h++){
                        if(cy+posy[h]>=0 && cy+posy[h]<y && cx+posx[h]>=0 && cx+posx[h]<x && mat[cy+posy[h]][cx+posx[h]]=='W'){
                            mat[cy+posy[h]][cx+posx[h]]='.';
                            cola.push(make_pair(cy+posy[h],cx+posx[h]));
                        }
                    }
                }
            }
        }
    }
    cout<<con;
    return 0;
}
