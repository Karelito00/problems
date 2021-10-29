#include <bits/stdc++.h>

using namespace std;

int z[10];
int org[10];
int n[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>m;
    for(int h=0;h<m;h++){
    for(int h=0;h<=9;h++){
        cin>>z[h];
        n[h]=h;
    }
    for(int o=9;o>=0;o--){
        int t=z[o],k=9;
        while(1){
            if(t==0 && n[k]!=-1){
                org[o]=n[k];
                n[k]=-1;
                break;
            }
            if(n[k]!=-1 && t!=0)
                t--;
            k--;
        }
    }
    for(int y=0;y<=9;y++)
        cout<<org[y]<<" ";
        cout<<"\n";
    }
    return 0;
}
