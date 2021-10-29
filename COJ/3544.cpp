#include <bits/stdc++.h>

using namespace std;

int y,x;
char mat[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int pos[]={1,-1,0,0};
int maxm;
pair <int,int> ptos;
void dfs( pair < int , int > coord ){
   for(int i=0;i<4;i++){
        int cy=pos[i],cx=pos[3-i];
        if(cy+coord.first>=0 && cy+coord.first<y && cx+coord.second>=0 && cx+coord.second<x && mat[cy+coord.first][cx+coord.second]=='.' && visited[cy+coord.first][cx+coord.second]==false){
           visited[cy+coord.first][cx+coord.second]=true;
           dist[cy+coord.first][cx+coord.second]=dist[coord.first][coord.second]+1;
           if(maxm<dist[cy+coord.first][cx+coord.second]){
            maxm=dist[cy+coord.first][cx+coord.second];
            ptos=make_pair(cy+coord.first,cx+coord.second);
           }
           dfs(make_pair(cy+coord.first,cx+coord.second));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        pair <int,int> ini;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='.')
                    ini.first=i,ini.second=j;
            }
        }
        maxm=0;
        dist[ini.first][ini.second]=0;
        visited[ini.first][ini.second]=true;
        dfs(ini);
        maxm=0;
        memset(visited,0,sizeof visited);
        visited[ptos.first][ptos.second]=true;
        dist[ptos.first][ptos.second]=0;
        dfs(ptos);
        cout<<"Maximum rope length is "<<maxm<<".\n";
        memset(visited,0,sizeof visited);
    }
    return 0;
}
