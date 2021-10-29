#include <bits/stdc++.h>

using namespace std;
vector <int> nodos[2000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int v,e;
        cin>>v>>e;
        if(v==0 && e==0)
            break;
        for(int i=0;i<e;i++){
            int nod,nod1,vert;
            cin>>nod>>nod1>>vert;
            nodos[nod-1].push_back(nod1-1);
            if(vert==2)
                nodos[nod1-1].push_back(nod-1);
        }
        queue <int> cola;
        vector <bool> visited(v);
        int real_c=0;
        for(int p=0;p<v;p++){
                cola.push(p);
                int con=1;
                visited[p]=true;
        while(!cola.empty()){
            int V=cola.front();
            cola.pop();
            for(int i=0;i<nodos[V].size();i++){
                int Estado=nodos[V][i];
                if(visited[Estado]==false){
                    visited[Estado]=true;
                    cola.push(Estado);
                    con++;
            }
        }
        }
        for(int l=0;l<visited.size();l++){
            visited[l]=false;
        }
        if(con==v)
            real_c++;
        else if(con<v)
            break;
        }
        if(real_c==v)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
            for(int m=0;m<v;m++){
                nodos[m].clear();
            }

        }
    return 0;
}
