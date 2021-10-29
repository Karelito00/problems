#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y = 0;
    int num = 0;
    bool correct = true;
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
            if(cuad[funt(y,x)][m - '0'] || row[y][m - '0'] || column[x][m - '0'])
                correct = false;
            cuad[funt(y,x)][m - '0'] = true;
            row[y][m - '0'] = true;
            column[x][m - '0'] = true;
            x++;
        }
        if(i != 3 && i != 7)
            y++;
    }
    cout<<(correct ? "CORRECT" : "WRONG");
    return 0;
}
