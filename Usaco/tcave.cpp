#include <bits/stdc++.h>

using namespace std;
vector <int> nodos[5000];
class Elements{
public:
    int dist;
    vector <int> caminos;
    Elements(){}
};
Elements cmd[5000];
bool visited[5000];
int main()
{
    freopen("tcave.in","r",stdin);
    freopen("tcave.out","w",stdout);
    int a,t,fin;
    cin>>a>>t>>fin;
    fin--;
    for(int i=0;i<t;i++){
        int nod,ady1,ady2;
        cin>>nod>>ady1>>ady2;
        nod--;
        ady1--;
        ady2--;
        nodos[nod].push_back(ady1);
        nodos[nod].push_back(ady2);
    }
    queue <int> cola;
    cola.push(0);
    visited[0]=true;
    cmd[0].dist=0;
    cmd[0].caminos.push_back(1);
    while(!cola.empty()){
        int v=cola.front();
        cola.pop();
        for(int k=0;k<nodos[v].size();k++){
            int to=nodos[v][k];
            if(visited[to]==false){
                visited[to]=true;
                cola.push(to);
                cmd[to].dist=cmd[v].dist+1;
                cmd[to].caminos=cmd[v].caminos;
                cmd[to].caminos.push_back(to+1);
            }
        }
    }
    cout<<cmd[fin].dist+1<<endl;
    for(int y=0;y<cmd[fin].caminos.size();y++)
        cout<<cmd[fin].caminos[y]<<endl;
    return 0;
}
