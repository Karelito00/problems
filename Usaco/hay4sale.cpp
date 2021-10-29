#include <bits/stdc++.h>

using namespace std;
vector <int> objetos;
int table[50000];
int main()
{
    freopen("hay4sale.in","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int m,c;
    cin>>m>>c;
    for(int b=0;b<c;b++){
        int n;
        cin>>n;
        objetos.push_back(n);
    }
    for(int l=m;l>=objetos[0];l--)
        table[l]=objetos[0];
    for(int i=1;i<c-1;i++){
        for(int k=m;k>=objetos[i];k--){
            table[k]=max(objetos[i],max(table[k-objetos[i]]+objetos[i],table[k]));
        }
    }
    cout<<max(table[m],max(table[m-objetos[c-1]]+objetos[c-1],objetos[0]));
    return 0;
}
