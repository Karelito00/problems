#include <bits/stdc++.h>

using namespace std;
class Element{
public:
    int pos;
    char k;
    Element(int pos1,char k1){
        pos=pos1;
        k=k1;
    }
    Element();
    bool operator < (const Element& hola)const{
        return hola.k < k;
    }
};
int arra[100001];
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
        string s;
        cin>>s;
        for(int u=0;u<n;u++){
            if(u==0)
                cola.push(Element(u,s[u]));
            else if(u>0){
                if(s[u] > cola.top().k){
                    while(s[u] > cola.top().k && !cola.empty()){
                        arra[cola.top().pos]=u;
                        cola.pop();
                    }
                }
                cola.push(Element(u,s[u]));
            }
        }
        for(int u=0;u<n;u++){
            if(arra[u]==0)
                cout<<-1<<" ";
            else
                cout<<arra[u]+1<<" ";
        }
        cout<<"\n";
        memset(arra,0,sizeof arra);
    }
    return 0;
}
