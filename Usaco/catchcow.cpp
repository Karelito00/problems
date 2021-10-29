#include <bits/stdc++.h>

using namespace std;
int table[100001];
int posx[]={1,-1};
int main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    int ini,cow;
    cin>>ini>>cow;
    if(ini==cow){
        cout<<0;
        return 0;
    }
    queue <int> cola;
    cola.push(ini);
    while(!cola.empty()){
        int pos=cola.front();
        cola.pop();
        for(int i=0;i<2;i++){
            if(pos+posx[i]<100001 && pos+posx[i]>=0 && table[pos+posx[i]]==0){
                table[pos+posx[i]]=table[pos]+1;
                cola.push(pos+posx[i]);
            }
        }
        if(pos*2<100001 && table[pos*2]==0){
            table[pos*2]=table[pos]+1;
            cola.push(pos*2);
        }
    }
    cout<<table[cow];
    return 0;
}
