#include <bits/stdc++.h>

using namespace std;

class Elements{
public:
    long long p;
    long long g;
    Elements(long long p1,long long g1){
        p=p1;
        g=g1;
    }
    Elements(){}
    bool operator < (const Elements& hola)const{
        return abs(min(hola.p*2,hola.g)-min(hola.p,hola.g)) > abs(min(p*2,g)-min(p,g));
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue < Elements > cola;
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        long long pro,gen;
        cin>>pro>>gen;
        cola.push(Elements(pro,gen));
    }
    long long suma=0;
    while(d>0){
        suma+=min(cola.top().p*2,cola.top().g);
        cola.pop();
        d--;
    }
    while(!cola.empty()){
        suma+=min(cola.top().p,cola.top().g);
        cola.pop();
    }
    cout<<suma;
    return 0;
}
