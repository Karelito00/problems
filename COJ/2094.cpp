#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int posy[]={1,-1,0,0};
int posx[]={0,0,1,-1};
string mat[MAX];

int main()
{
    int y,x;
    cin>>y>>x;
    for(int i=0;i<y;i++){
        cin>>mat[i];
    }
    int best=0,cant=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(mat[i][j]=='1'){
                mat[i][j]='0';
                cant++;
                int con=1;
                queue < pair <int,int> > cola;
                cola.push(make_pair(i,j));
                while(!cola.empty()){
                    int y1=cola.front().first;
                    int x1=cola.front().second;
                    cola.pop();
                    for(int h=0;h<4;h++){
                        int cy=posy[h],cx=posx[h];
                        if(cy+y1>=0 && cy+y1<y && cx+x1>=0 && cx+x1<x && mat[cy+y1][cx+x1]=='1'){
                            mat[cy+y1][cx+x1]='0';
                            cola.push(make_pair(cy+y1,cx+x1));
                            con++;
                        }
                    }
                }
                best=max(con,best);
            }
        }
    }
    cout<<cant<<" "<<best;
    return 0;
}
