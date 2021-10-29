#include <bits/stdc++.h>

using namespace std;

int mat[100][100];
int a,b;

void accumu_table(){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            mat[i][j]=(mat[i][j]+mat[i-1][j]+mat[i][j-1])-mat[i-1][j-1];
        }
    }
}

int main()
{
    freopen("goodgrs.in","r",stdin);
    freopen("goodgrs.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat[i][j];
        }
    }
    accumu_table();
    int may=0,y=0,x=0;
    for(int i=2;i<a;i++){
        for(int j=2;j<b;j++){
            int val=mat[i][j]-mat[i-3][j]-mat[i][j-3]+mat[i-3][j-3];
            if(val > may){
                may=val;
                y=i;
                x=j;
            }
        }
    }
    cout<<may<<endl<<y-1<<" "<<x-1;
    return 0;
}
