#include <bits/stdc++.h>

using namespace std;

bool mat[10][10];

int main()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>mat[i][j];
        }
    }
    bool puede= false;
    if(mat[0][3]){
        if(mat[0][0] || mat[0][1] || mat[0][2] || mat[1][0] || mat[2][1] || mat[3][2]){
            puede = true;
        }
    }
    if(mat[1][3]){
        if(mat[1][0] || mat[1][1] || mat[1][2] || mat[2][0] || mat[3][1] || mat[0][2]){
            puede = true;
        }
    }
    if(mat[2][3]){
        if(mat[2][0] || mat[2][1] || mat[2][2] || mat[3][0] || mat[0][1] || mat[1][2]){
            puede = true;
        }
    }
    if(mat[3][3]){
        if(mat[3][0] || mat[3][1] || mat[3][2] || mat[0][0] || mat[1][1] || mat[2][2]){
            puede = true;
        }
    }
    if(puede)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
