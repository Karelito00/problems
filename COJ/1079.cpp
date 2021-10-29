#include <bits/stdc++.h>

using namespace std;
int mat[102][102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int tr;
        cin>>tr;
        int var=1,best=0;
        for(int i=1;i<=tr;i++){
            for(int j=1;j<=var;j++){
                cin>>mat[i][j];
                if(var>=2)
                    mat[i][j]+=max(mat[i-1][j],mat[i-1][j-1]);
                if(i==tr)
                    best=max(best,mat[i][j]);
            }
            var++;
        }
        cout<<best<<"\n";
    }
    return 0;
}
