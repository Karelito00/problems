#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int posy[] = {1,0,-1,0};
int posx[] = {0,1,0,-1};

bool mark[6][6];
int pasto;

bool cond(int by, int cy, int bx, int cx){
    if(by + cy < 1 || by + cy > 5)
        return false;
    if(bx + cx < 1 || bx + cx > 5)
        return false;
    if(mark[by + cy][bx + cx])
        return false;
    return true;
}

bool funt(int by, int bx, int my, int mx){
    for(int i = 0; i < 4; i++){
        int cy = posy[i], cx = posx[i];
        if(cond(by, cy, bx, cx)){
            for(int j = 0; j < 4; j++){
                if(cond(my, posy[j], mx, posx[j]))
                    return true;
            }
        }
    }
    return false;
}

int sol;

void backtracking(int by, int bx, int bc, int my, int mx, int mc){
    if(bc + mc == pasto - 1){
        if(funt(by, bx, my, mx)) sol++;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(cond(by, posy[i], bx, posx[i])){
            mark[by + posy[i]][bx + posx[i]] = true;
            for(int j = 0; j < 4; j++){
                if(cond(my, posy[j], mx, posx[j])){
                    mark[my + posy[j]][mx + posx[j]] = true;
                    backtracking(by + posy[i], bx + posx[i], bc + 1, my + posy[j], mx + posx[j], mc + 1);
                    mark[my + posy[j]][mx + posx[j]] = false;
                }
            }
            mark[by + posy[i]][bx + posx[i]] = false;
        }
    }
}

int main()

{
    freopen("grazing.in","r",stdin);
    freopen("grazing.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pasto = 25 - n;
    for(int i = 0; i < n; i++){
        int y, x;
        cin>>y>>x;
        mark[y][x] = true;
    }
    mark[1][1] = true;
    mark[5][5] = true;
    backtracking(1, 1, 1, 5, 5, 1);
    cout<<sol;
    return 0;
}
