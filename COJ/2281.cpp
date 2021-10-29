#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        int n=sqrt(s.size());
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=s[c];
                c++;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                cout<<mat[j][i];
            }
        }
        cout<<"\n";
    }
    return 0;
}
