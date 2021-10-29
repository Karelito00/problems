#include <bits/stdc++.h>

using namespace std;
int posx[4]={1,0,-1,0};
int posy[4]={0,1,0,-1};
pair <int,int> z[10000];
int mat[1000][1000];

int main()
{
    freopen("mud.in","r",stdin);
    freopen("mud.out","w",stdout);
    int x,y,test;
    cin>>x>>y>>test;
    x+=500;
    y+=500;
    for(int u=0;u<test;u++){
        int x1,y1;
        cin>>x1>>y1;
        x1+=500;
        y1+=500;
        z[u].first=x1;
        z[u].second=y1;
    }
    for(int y=0;y<test;y++){
       mat[1000-z[y].first][1000-z[y].second]=-1;
    }
    queue < pair <int,int> > cola;
    cola.push(make_pair(500,500));
    while(!cola.empty()){
        pair <int,int> v=cola.front();
        cola.pop();
        if(v.first==1000-x && v.second==1000-y)
            break;
        for(int u=0;u<4;u++){
            int cy=v.first;
            int cx=v.second;
            if(cy+posy[u]>=0 && cy+posy[u]<1000 && cx+posx[u]>=0 && cx+posx[u]<=1000 && mat[cy+posy[u]][cx+posx[u]]==0){
                cola.push(make_pair(cy+posy[u],cx+posx[u]));
                mat[cy+posy[u]][cx+posx[u]]=mat[cy][cx]+1;
            }
        }
    }
    cout<<mat[1000-x][1000-y];
    return 0;
}
