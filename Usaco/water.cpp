#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> pii;
vector <pii> nodos[305];
bool visited[305];
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    int a;
    cin>>a;
    priority_queue < pii , vector <pii> , greater <pii> > cola;
    for(int b=0;b<a;b++){
        int l;
        cin>>l;
        cola.push(make_pair(l,b));
    }
    int ct=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            int n;
            cin>>n;
            if(ct<j){
                nodos[i].push_back(make_pair(j,n));
                nodos[j].push_back(make_pair(i,n));
            }
        }
        ct++;
    }
    int suma=0;
    while(!cola.empty()){
        pii v=cola.top();
        cola.pop();
        int n=v.second,peso=v.first;
        if(visited[n]==false){
            suma+=peso;
            visited[n]=true;
            for(int y=0;y<nodos[n].size();y++){
                cola.push(make_pair(nodos[n][y].second,nodos[n][y].first));
            }
        }
    }
    cout<<suma;
    return 0;
}
