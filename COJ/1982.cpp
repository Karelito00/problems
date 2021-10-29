#include <bits/stdc++.h>

using namespace std;

char mat[51][51];
int dist[51][51];
int pos[]={1,-1,0,0};
int con;
vector < pair < int , int > > man1;
vector < pair < int , int > > man2;
int y,x;

void bfs(pair < int,int > ini){
    queue < pair < int ,int > > cola;
    cola.push(ini);
    while(!cola.empty()){
        int y1=cola.front().first;
        int x1=cola.front().second;
        cola.pop();
        bool flag=false;
        for(int u=0;u<4;u++){
            int cy=pos[u],cx=pos[3-u];
            if(cy+y1>=0 && cy+y1<y && cx+x1>=0 && cx+x1<x && mat[cy+y1][cx+x1]=='X'){
                cola.push(make_pair(cy+y1,cx+x1));
                mat[cy+y1][cx+x1]='*';
            }
            else if(cy+y1>=0 && cy+y1<y && cx+x1>=0 && cx+x1<x && mat[cy+y1][cx+x1]=='.')
                flag=true;
        }
        if(flag==true){
            if(con==0)
                man1.push_back(make_pair(y1,x1));
            else
                man2.push_back(make_pair(y1,x1));
        }
    }
}
int main()
{
    cin>>y>>x;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='X'){
                mat[i][j]='*';
                bfs(make_pair(i,j));
                con++;
            }
        }
    }
    int best=999999;
    for(int i=0;i<man1.size();i++){
        for(int j=0;j<man2.size();j++){
            best=min(best,abs(man1[i].first-man2[j].first)+abs(man1[i].second-man2[j].second));
        }
    }
    cout<<best-1;
    return 0;
}
