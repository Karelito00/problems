#include <bits/stdc++.h>

using namespace std;
struct Estado{
public:
    int valor;
    int pos;
    Estado(int v,int p){
     valor=v;
     pos=p;
    }
    bool operator < (const Estado& hola) const{
        return valor < hola.valor;
    }
};
Estado z[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int casos;
    cin>>casos;
    while(casos--){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    priority_queue <Estado> cola;
    int c=0,p=k;
    for(int i=0;i<n;i++){
        if(i<k){
            cola.push(Estado(z[i],i));
            if(i==k-1){
                cout<<cola.top().valor<<" ";
                c++;
                p++;
            }

        }
        else if(i>=p-1){
                cola.push(Estado(z[i],i));
            while(cola.top().pos<c){
                cola.pop();
            }
            cout<<cola.top().valor<<" ";
            p++;
        c++;
        }
    }
    cout<<"\n";
    }
    return 0;
}
