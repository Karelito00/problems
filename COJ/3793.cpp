#include <bits/stdc++.h>

using namespace std;

class Elements{
public:
    int id;
    string s;
    int suma;
    int base;
    Elements(int id1,string s1,int suma1,int base1){
        id = id1;
        s = s1;
        suma = suma1;
        base = base1;
    }
    bool operator < (const Elements& hola)const{
        if(suma!=hola.suma)
            return suma > hola.suma;
        else
            return id > hola.id;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue < Elements > cola;
        for(int i=0;i<n;i++){
            string st;
            int tim;
            cin>>st>>tim;
            cola.push(Elements(i+1,st,tim,tim));
        }
        while(k--){
            Elements yy = cola.top();
            cout<<yy.suma<<" "<<yy.s<<"\n";
            cola.pop();
            cola.push(Elements(yy.id,yy.s,yy.suma+yy.base,yy.base));
        }
    }
    return 0;
}
