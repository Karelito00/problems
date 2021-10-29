#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef pair < int , int > par;
int mat[10][10];
int posy[] = {2, 2, -2, -2, 1, -1, 1, -1};
int posx[] = {1, -1, 1, -1, 2, 2, -2, -2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        int finy = b[0] - 'a' + 1, finx = b[1] - '0';
        queue < par > cola;
        cola.push(mp(a[0] - 'a' + 1, a[1] - '0'));
        mat[a[0] - 'a' + 1][a[1] - '0'] = 1;
        while(!cola.empty()){
            par v = cola.front();
            cola.pop();
            for(int i = 0; i < 8; i++){
                int cy = posy[i], cx = posx[i];
                if(v.f + cy >= 1 && v.f + cy <= 8 && v.s + cx >= 1 && cx + v.s <= 8 && !mat[v.f + cy][v.s + cx]){
                    mat[v.f + cy][v.s + cx] = mat[v.f][v.s] + 1;
                    cola.push(mp(v.f + cy, v.s + cx));
                }
            }
        }
        cout<<mat[finy][finx] - 1<<"\n";
        for(int i = 1; i <= 8; i++)
            fill(mat[i] + 1, mat[i] + 9, 0);
    }
    return 0;
}
