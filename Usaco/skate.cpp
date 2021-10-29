#include <bits/stdc++.h>

using namespace std;
char mat[113][113];
int ka[113][113];
vector < pair <int,int> > caminos[9999];
int posy[]={1,0,-1,0};
int posx[]={0,1,0,-1};
int main()
{
    freopen("skate.in","r",stdin);
    freopen("skate.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat[i][j];
        }
    }
    int c=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            ka[i][j]=c;
            c++;
        }
    }
    queue < pair <int,int> > cola;
    cola.push(make_pair(0,0));
    caminos[0].push_back(make_pair(1,1));
    while(!cola.empty()){
        pair <int,int> v=cola.front();
        cola.pop();
        int cy=v.first,cx=v.second;
        for(int k=0;k<4;k++){
            if(cy+posy[k]>=0 && cy+posy[k]<a && cx+posx[k]>=0 && cx+posx[k]<b && mat[cy+posy[k]][cx+posx[k]]=='.'){
                mat[cy+posy[k]][cx+posx[k]]='*';
                caminos[ka[cy+posy[k]][cx+posx[k]]]=caminos[ka[cy][cx]];
                caminos[ka[cy+posy[k]][cx+posx[k]]].push_back(make_pair(cy+posy[k],cx+posx[k]));
                cola.push(make_pair(cy+posy[k],cx+posx[k]));
            }
        }
    }
    cout<<1<<" "<<1<<endl;
    for(int i=1;i<caminos[ka[a-1][b-1]].size();i++)
        cout<<caminos[ka[a-1][b-1]][i].first+1<<" "<<caminos[ka[a-1][b-1]][i].second+1<<endl;
    return 0;
}
