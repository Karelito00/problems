#include <bits/stdc++.h>
#define MAX 10
using namespace std;

char z[MAX][MAX];
int z1[MAX][MAX];
int a,fin,inicio;
vector <int> nodos[100];
void relleno_nod(){
    for(int u=0;u<a;u++){
        for(int j=0;j<a;j++){
            if(u-1>=0 && z1[u][j]!=-1 && z1[u-1][j]!=-1)
                nodos[z1[u][j]].push_back(z1[u-1][j]);
            if(u+1<a && z1[u][j]!=-1 && z1[u+1][j]!=-1)
                nodos[z1[u][j]].push_back(z1[u+1][j]);
            if(j-1>=0 && z1[u][j]!=-1 && z1[u][j-1]!=-1)
                nodos[z1[u][j]].push_back(z1[u][j-1]);
            if(j+1<a && z1[u][j]!=-1 && z1[u][j+1]!=-1)
                nodos[z1[u][j]].push_back(z1[u][j+1]);
        }
    }
}
int main()
{
    cin>>a;
    for(int b=0;b<a;b++){
        for(int c=0;c<a;c++){
            cin>>z[b][c];
        }
    }
    int c=0;
    for(int y=0;y<a;y++){
        for(int g=0;g<a;g++){
            if(z[y][g]=='m'){
                inicio=c;
                z1[y][g]=c;
                c++;
            }
            else if(z[y][g]=='#'){
                fin=c;
                z1[y][g]=c;
                c++;
            }
            else if(z[y][g]!='*'){
                z1[y][g]=c;
                c++;
            }
            else if(z[y][g]=='*'){
                z1[y][g]=-1;
            }
        }
    }
    relleno_nod();
    vector <bool> visited(a*a);
    int distancias[100];
    memset(distancias,0,sizeof distancias);
    queue <int> cola;
    cola.push(inicio);
    visited[inicio]=true;
    while(!cola.empty()){
        int vertice=cola.front();
        cola.pop();
        visited[vertice]=true;
        for(int u=0;u<nodos[vertice].size();u++){
            int to=nodos[vertice][u];
            if(visited[to]==false){
                visited[to]=true;
                cola.push(nodos[vertice][u]);
                distancias[to]=distancias[vertice]+1;
            }
        }
    }
    if(distancias[fin]!=0)
    cout<<distancias[fin];
    else
        cout<<-1;
    return 0;
}
