#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define f first
#define s second
#define par pair < int , int >

using namespace std;

char mat[55][55];
int posx[] = {1,0,-1,0};
int posy[] = {0,1,0,-1};
bool visited[55][55];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>mat[i][j];
        }
    }
    queue < par > cola;
    int sol = 0, cont = 0;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            if(mat[i][j] == '*' && visited[i][j] == false){
                int con = 1;
                int x2 = j, y2 = i, x1 = j, y1 = i;
                cola.push(mp(i,j));
                visited[i][j] = true;
                while(!cola.empty()){
                    par v = cola.front();
                    cola.pop();
                    for(int i = 0; i < 4; i++){
                        int cx = posx[i], cy = posy[i];
                        if(v.f + cy >= 1 && v.f + cy <= n && v.s + cx >= 1 && v.s + cx <= m && !visited[v.f + cy][v.s + cx] && mat[v.f + cy][v.s + cx] == '*'){
                            cola.push(mp(v.f + cy, v.s + cx));
                            visited[v.f + cy][v.s + cx] = true;
                            con++;
                            x1 = mn(x1, v.s + cx);
                            x2 = mx(x2, v.s + cx);
                            y1 = mn(y1, v.f + cy);
                            y2 = mx(y2, v.f + cy);
                        }
                    }
                }
                int nx = x2 - (x1 - 1);
                int ny = y2 - (y1 - 1);
                if(nx == ny && nx * ny == con)
                    sol++;
                cont++;
            }
        }
    }
    cout<<(sol == cont && cont == 1 ? "YES" : "NO");
    return 0;
}
