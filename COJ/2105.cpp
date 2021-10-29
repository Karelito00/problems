#include <bits/stdc++.h>

using namespace std;
char mat[1001][1001];
int pos[]={1,-1,0,0};
int main()
{
    int y,x;
    cin>>y>>x;
    pair <int,int> ini;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='+')
                ini.first=i,ini.second=j;
        }
    }
    queue < pair <int,int> > cola;
    int con=0;
    cola.push(ini);
    mat[ini.first][ini.second]='*';
    while(!cola.empty()){
        int y1=cola.front().first;
        int x1=cola.front().second;
        cola.pop();
        bool flag=false;
        for(int h=0;h<4;h++){
            int cy=pos[h],cx=pos[3-h];
            if(cy+y1>=0 && cy+y1<y && cx+x1<x && cx+x1>=0 && mat[cy+y1][cx+x1]=='+'){
                cola.push(make_pair(cy+y1,cx+x1));
                mat[cy+y1][cx+x1]='*';
            }
            else if(cy+y1>=0 && cy+y1<y && cx+x1<x && cx+x1>=0 && mat[cy+y1][cx+x1]=='-')
                flag=true;
        }
        if(flag)
            con++;
    }
    cout<<con;
    return 0;
}
