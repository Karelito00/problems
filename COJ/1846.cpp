#include <bits/stdc++.h>

using namespace std;
int mat[20][20];
int main()
{
    int a,b;
    cin>>a>>b;
    int space=0;
    int x=b;
    for(int y=0;y<a;y++){
        x+=y;
        if(x>=10){
            while(x>=10){
                x-=9;
            }
        }
        mat[0][y]=x;
    }
    for(int u=1;u<a;u++){
        for(int i=space;i<a;i++){
            int j=mat[u-1][i]+1;
            if(j==10)
                j=1;
            mat[u][i]=j;
        }
        space++;
    }
    space=0;
    int n=0;
    for(int i=0;i<a;i++){
        for(int o=0;o<space;o++){
            cout<<" ";
        }
        for(int x=n;x<a;x++){
            cout<<mat[i][x]<<" ";
        }
        space+=2;
        n++;
        cout<<endl;
    }
    return 0;
}
