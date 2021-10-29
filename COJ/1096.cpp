#include <bits/stdc++.h>

using namespace std;
bool visited[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,m,d;
        cin>>n>>m>>d;
        vector <int> adya[10000];
        for(int i=0;i<m;i++){
            int ady1,ady2;
            cin>>ady1>>ady2;
            ady1--;
            ady2--;
            adya[ady1].push_back(ady2);
        }
        int con=0;
        for(int j=0;j<d;j++){
            int num;
            cin>>num;
            queue <int> cola;
            cola.push(num-1);
            if(visited[num-1]==false){
                    con++;
            visited[num-1]=true;
            while(!cola.empty()){
                int v=cola.front();
                cola.pop();
                for(int k=0;k<adya[v].size();k++){
                    int to=adya[v][k];
                    if(visited[to]==false){
                        visited[to]=true;
                        cola.push(to);
                        con++;
                    }
                }
            }
            }
        }
        cout<<con<<"\n";
        memset(visited,false,sizeof (visited));
    }
    return 0;
}
