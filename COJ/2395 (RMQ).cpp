#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)
#define mn(a,b) (a < b ? a : b)

using namespace std;

int n,q;
struct par{
    int mayor;
    int menor;
};

par ST[50001][16];

void build(){
    for(int e=1;(1<<e)<=n;e++){
        int l = (1<<e);
        for(int i=1;i<=n-l+1;i++){
            ST[i][e].mayor = mx(ST[i][e-1].mayor,ST[i + l/2][e-1].mayor);
            ST[i][e].menor = mn(ST[i][e-1].menor,ST[i + l/2][e-1].menor);
        }
    }
}
par query(int a,int b){
    par l;
    int lg = log2(b - a + 1);
    l.mayor = mx(ST[a][lg].mayor,ST[b - (1<<lg) + 1][lg].mayor);
    l.menor = mn(ST[a][lg].menor,ST[b - (1<<lg) + 1][lg].menor);
    return l;
}
int main()
{
    freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ST[i][0].mayor;
        ST[i][0].menor = ST[i][0].mayor;
    }

    build();
    while(q--){
        int n1,n2;
        cin>>n1>>n2;
        par tt = query(n1,n2);
        cout<<tt.mayor-tt.menor<<"\n";
    }
    return 0;
}
