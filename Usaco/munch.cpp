#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int matr[100][100];
int posx[]={1,0,-1,0};
int posy[]={0,1,0,-1};
int distancia[100000];
int main()
{
    freopen("munch.in","r",stdin);
    freopen("munch.out","w",stdout);
    int a,b;
    cin>>a>>b;
    pair <int, int> posini,posfinal;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='B'){
                posini=make_pair(i,j);
            }
            if(mat[i][j]=='C'){
                posfinal=make_pair(i,j);
            }
        }
    }
    int c=1;
    for(int i=0;i<a;i++){
        for(int h=0;h<b;h++){
            if(mat[i][h]!='*'){
            matr[i][h]=c;
            c++;
            }else
            matr[i][h]=-1;
        }
    }
    int ini=matr[posini.first][posini.second],fin=matr[posfinal.first][posfinal.second];
    vector <int> nodos[100000];
    for(int i=0;i<a;i++){
        for(int h=0;h<b;h++){
            if(matr[i][h]!=-1){
            for(int k=0;k<4;k++){
                if(h+posx[k]>=0 && h+posx[k]<b && i+posy[k]>=0 && i+posy[k]<a && matr[i+posy[k]][h+posx[k]]!=-1)
                    nodos[matr[i][h]].push_back(matr[i+posy[k]][h+posx[k]]);
            }
            }
        }
    }
    vector <bool> visited(a*b);
    queue <int> cola;
    cola.push(ini);
    while(!cola.empty()){
        int v=cola.front();
        cola.pop();
        visited[v]=true;
        for(int i=0;i<nodos[v].size();i++){
            int to=nodos[v][i];
            if(visited[to]==false){
                visited[to]=true;
                cola.push(to);
                distancia[to]=distancia[v]+1;
            }
        }
    }
    cout<<distancia[fin];
    return 0;
}
