#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
bool vist[100][100];
int posy[]={1,0,-1,0};
int posx[]={0,1,0,-1};
int main()
{
    freopen("cowart.in","r",stdin);
    freopen("cowart.out","w",stdout);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>mat[i][j];
        }
    }
    int cant=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(vist[i][j]==false){
                cant++;
                vist[i][j]=true;
                queue < pair <int,int> > cola;
                cola.push(make_pair(i,j));
                while(!cola.empty()){
                    pair <int,int> v=cola.front();
                    cola.pop();
                    if(mat[i][j]=='R' || mat[i][j]=='G'){
                    int cy=v.first,cx=v.second;
                    for(int k=0;k<4;k++){
                        if(cy+posy[k]>=0 && cy+posy[k]<a && cx+posx[k]>=0 && cx+posx[k]<a && mat[cy+posy[k]][cx+posx[k]]!='B' && vist[cy+posy[k]][cx+posx[k]]==false){
                            vist[cy+posy[k]][cx+posx[k]]=true;
                            cola.push(make_pair(cy+posy[k],cx+posx[k]));
                        }
                    }
                    }
                    else{
                    int cy=v.first,cx=v.second;
                    for(int k=0;k<4;k++){
                        if(cy+posy[k]>=0 && cy+posy[k]<a && cx+posx[k]>=0 && cx+posx[k]<a && mat[cy+posy[k]][cx+posx[k]]!='G' && mat[cy+posy[k]][cx+posx[k]]!='R' && vist[cy+posy[k]][cx+posx[k]]==false){
                            vist[cy+posy[k]][cx+posx[k]]=true;
                            cola.push(make_pair(cy+posy[k],cx+posx[k]));
                        }
                    }
                    }
                }
            }
        }
    }
    memset(vist, false ,sizeof (vist));
    int cant2=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(vist[i][j]==false){
                cant2++;
                vist[i][j]=true;
                queue < pair <int,int> > cola;
                cola.push(make_pair(i,j));
                while(!cola.empty()){
                    pair <int,int> v=cola.front();
                    cola.pop();
                    int cy=v.first,cx=v.second;
                    for(int k=0;k<4;k++){
                        if(cy+posy[k]>=0 && cy+posy[k]<a && cx+posx[k]>=0 && cx+posx[k]<a && mat[cy+posy[k]][cx+posx[k]]==mat[cy][cx] && vist[cy+posy[k]][cx+posx[k]]==false){
                            vist[cy+posy[k]][cx+posx[k]]=true;
                            cola.push(make_pair(cy+posy[k],cx+posx[k]));
                        }
                    }
                }
            }
        }
    }
    cout<<cant2<<" "<<cant;
    return 0;
}
