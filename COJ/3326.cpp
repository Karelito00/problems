#include <bits/stdc++.h>

using namespace std;
class Element{
public:
    int pos;
    string k;
    Element(int pos1,string k1){
        pos=pos1;
        k=k1;
    }
    Element();
    bool operator < (const Element& hola)const{
        return hola.k < k;
    }
};
int arra[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n;
        cin>>n;
        priority_queue < Element > cola;
        for(int u=0;u<n;u++){
            string s;
            cin>>s;
            if(u==0)
                cola.push(Element(u,s));
            else if(u>0){
                if(s > cola.top().k){
                    pair <string,int> best;
                    best.second=0;
                    while(s > cola.top().k && !cola.empty()){
                        if(best.second<cola.top().pos){
                            best.second=cola.top().pos;
                            best.first=cola.top().k;
                        }
                        cola.pop();
                    }
                    arra[best.second]=u+1;
                }
                cola.push(Element(u,s));
            }
        }
        for(int u=0;u<n;u++){
            if(arra[u]==0)
                cout<<-1<<" ";
            else
                cout<<arra[u]<<" ";
        }
        cout<<"\n";
        memset(arra,0,sizeof arra);
    }
    return 0;
}
