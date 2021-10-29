#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

vector < pair < int , int > > coor;
int sudoku[10][10];
bool cuad[10][10];
bool column[10][10];
bool row[10][10];

int funt(int y, int x){
    if(y < 3){
        if(x < 3) return 1;
        if(x < 6) return 2;
        return 3;
    }
    if(y < 6){
        if(x < 3) return 4;
        if(x < 6) return 5;
        return 6;
    }
    if(x < 3) return 7;
    if(x < 6) return 8;
    return 9;
}

bool yes;

void view(int f){
    for(int i = 0; i < f; i++)
        cout<<"-";
}

void backtracking(int pos){
    if(pos == (int)coor.size()){
        yes = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<sudoku[i][j]<<" ";
                if(j == 2 || j == 5)
                    cout<<"| ";
            }
            cout<<"\n";
            if(i == 2 || i == 5){
                view(6);
                cout<<"+";
                view(7);
                cout<<"+";
                view(6);
                cout<<"\n";
            }
        }
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(!yes && !cuad[funt(coor[pos].f,coor[pos].s)][i] && !row[coor[pos].f][i] && !column[coor[pos].s][i]){
            cuad[funt(coor[pos].f,coor[pos].s)][i] = true;
            row[coor[pos].f][i] = true;
            column[coor[pos].s][i] = true;
            sudoku[coor[pos].f][coor[pos].s] = i;
            backtracking(pos + 1);
            cuad[funt(coor[pos].f,coor[pos].s)][i] = false;
            row[coor[pos].f][i] = false;
            column[coor[pos].s][i] = false;
            sudoku[coor[pos].f][coor[pos].s] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y = 0;
    int num = 0;
    for(int i = 0; i < 11; i++){
        int x = 0;
        if(i == 3 || i == 7)
            num = 21;
        else
            num = 11;
        for(int j = 0; j < num; j++){
            char m;
            cin>>m;
            if(i == 3 || i == 7 || j == 3 || j == 7)
                continue;
            if(m != '*'){
                sudoku[y][x] = m - '0';
                cuad[funt(y,x)][m - '0'] = true;
                row[y][m - '0'] = true;
                column[x][m - '0'] = true;
            }
            else
                coor.push_back(make_pair(y,x));
            x++;
        }
        if(i != 3 && i != 7)
            y++;
    }
    backtracking(0);
    return 0;
}
