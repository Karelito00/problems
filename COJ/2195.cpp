#include <bits/stdc++.h>

using namespace std;

class Elements{
public:
    int m;
    int pos;
    Elements(int m1,int pos1){
        m=m1;
        pos=pos1;
    }
    Elements(){}
    bool operator < (const Elements& hola)const{
        return hola.m < m;
    }
};

priority_queue < Elements > cola;

int z[100001];

int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int l;
        scanf("%d",&l);
        if(i==0)
            cola.push(Elements(l,0));
        else if(l>cola.top().m){
            while(l>cola.top().m && !cola.empty()){
                z[cola.top().pos]=i+1;
                cola.pop();
            }
            cola.push(Elements(l,i));
        }
        else{
            cola.push(Elements(l,i));
        }
    }
    while(!cola.empty()){
        z[cola.top().pos]=0;
        cola.pop();
    }
    for(int h=0;h<a;h++)
        printf("%d\n",z[h]);
    return 0;
}
