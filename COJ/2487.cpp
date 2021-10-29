#include <bits/stdc++.h>

using namespace std;
vector < pair <int,int> > objetos;
int table[13000];
int main()
{
    int a,m;
    cin>>a>>m;
    for(int i=0;i<a;i++){
        int obj,peso;
        cin>>obj>>peso;
        objetos.push_back(make_pair(obj,peso));
    }
    for(int i=0;i<a;i++){
        for(int j=m;j>=objetos[i].first;j--){
            table[j]=max(table[j],max(objetos[i].second,objetos[i].second+table[j-objetos[i].first]));
        }
    }
    cout<<table[m];
    return 0;
}
