#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef pair < int , int > par;
int posy[] = {1, 1, -1, -1, 1, -1, 0, 0};
int posx[] = {1, -1, 1, -1, 0, 0, -1, 1};
char mat[105][105];
bool visited[105][105];
int n, m;
char cad[] = {'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
bool yes;

void DFS(int y, int x, int pos){
    if(pos == 9){
        yes = true;
        return;
    }
    for(int i = 0; i < 8; i++){
        int cy = posy[i], cx = posx[i];
        if(cy + y >= 1 && cy + y <= n && cx + x >= 1 && cx + x <= m && mat[cy + y][cx + x] == cad[pos] && !visited[cy + y][cx + x]){
            visited[cy + y][cx + x] = true;
            DFS(cy + y, cx + x, pos + 1);
            visited[cy + y][cx + x] = false;
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
        cin>>n>>m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cin>>mat[i][j];
        }
        yes = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!yes && mat[i][j] == 'A')
                    DFS(i, j, 0);
            }
        }
        if(yes) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
