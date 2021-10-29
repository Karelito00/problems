#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int posy[]={1,0,-1,0,1,-1,1,-1};
int posx[]={0,1,0,-1,1,-1,-1,1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int n;
         cin>>n;
         if(n==0)
            break;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
         }
         int cant=0,maxm=0,minm=100000;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='l'){
                    int tam=1;
                    mat[i][j]='s';
                    cant++;
                    queue < pair <int , int> > cola;
                    cola.push(make_pair(i,j));
                    while(!cola.empty()){
                        pair <int,int> v=cola.front();
                        cola.pop();
                        for(int u=0;u<8;u++){
                            int cy=v.first,cx=v.second;
                            if(cy+posy[u]>=0 && cy+posy[u]<n && cx+posx[u]>=0 && cx+posx[u]<n && mat[cy+posy[u]][cx+posx[u]]=='l'){
                              cola.push(make_pair(cy+posy[u],cx+posx[u]));
                              tam++;
                              mat[cy+posy[u]][cx+posx[u]]='s';
                            }
                        }
                    }
                    if(tam>maxm)
                        maxm=tam;
                    if(tam<minm)
                        minm=tam;
                }
            }
         }
         if(cant==0)
         cout<<cant<<" "<<0<<" "<<maxm<<"\n";
         else
            cout<<cant<<" "<<minm<<" "<<maxm<<"\n";
    }
    return 0;
}
