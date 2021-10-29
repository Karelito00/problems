#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct nod{
    char l[9][9];
    int y1, x1;
    int cant;
};

char mat[9][9];
vector < pair < int , int > > ini;
int n, con;

bool DFS(nod v){
    if(!v.cant) return true;
    nod aux = v;
    /** MOV #1 **/
    for(; aux.y1 >= 0; aux.y1--){
        if(aux.y1 - 1 < 0 || aux.l[aux.y1 - 1][aux.x1] == 'o')
            break;
        aux.l[aux.y1 - 1][aux.x1] = 'o';
        aux.cant--;
    }
    bool mov1 = false;
    if(aux.cant != v.cant) mov1 = DFS(aux);
    /** MOV #2 **/
    aux = v;
    for(; aux.y1 < n; aux.y1++){
        if(aux.y1 + 1 >= n || aux.l[aux.y1 + 1][aux.x1] == 'o')
            break;
        aux.l[aux.y1 + 1][aux.x1] = 'o';
        aux.cant--;
    }
    bool mov2 = false;
    if(aux.cant != v.cant) mov2 = DFS(aux);
    /** MOV #3 **/
    aux = v;
    for(; aux.x1 >= 0; aux.x1--){
        if(aux.x1 - 1 < 0 || aux.l[aux.y1][aux.x1 - 1] == 'o')
            break;
        aux.l[aux.y1][aux.x1 - 1] = 'o';
        aux.cant--;
    }
    bool mov3 = false;
    if(aux.cant != v.cant) mov3 = DFS(aux);
    /** MOV #4 **/
    aux = v;
    for(; aux.x1 < n; aux.x1++){
        if(aux.x1 + 1 >= n || aux.l[aux.y1][aux.x1 + 1] == 'o')
            break;
        aux.l[aux.y1][aux.x1 + 1] = 'o';
        aux.cant--;
    }
    bool mov4 = false;
    if(aux.cant != v.cant) mov4 = DFS(aux);
    return (mov1 || mov2 || mov3 || mov4 ? true : false);
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'x'){
                con++;
                ini.push_back(mp(i, j));
            }
        }
    }
    if(con == 0){
        cout<<"Yes";
        return 0;
    }
    for(int i = 0; i < con; i++){
        nod node;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                node.l[i][j] = mat[i][j];
        }
        node.cant = con - 1;
        node.l[ini[i].f][ini[i].s] = 'o';
        node.y1 = ini[i].f, node.x1 = ini[i].s;
        if(DFS(node)){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
