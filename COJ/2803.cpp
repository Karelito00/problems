#include <bits/stdc++.h>

using namespace std;

char mat[11][11];
int pos[]={1,-1,0,0};
int n;

bool bfs(){
    queue < pair <int,int> > cola;
    cola.push(make_pair(0,0));
    while(!cola.empty()){
        int y1=cola.front().first;
        int x1=cola.front().second;
        cola.pop();
        for(int u=0;u<4;u++){
            int cy=pos[u],cx=pos[3-u];
            if(cy+y1>=0 && cy+y1<n && cx+x1>=0 && cx+x1<n && mat[cy+y1][cx+x1]!='*'){
                if(mat[y1][x1]==mat[cy+y1][cx+x1])
                    return 0;
                cola.push(make_pair(cy+y1,cx+x1));
            }
        }
        mat[y1][x1]='*';
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
            cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        if(bfs())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
