#include <bits/stdc++.h>

using namespace std;

int table[50005];

int main()
{
    freopen("cowflix.in","r",stdin);
    freopen("cowflix.out","w",stdout);
    vector<int> objs;
    int a,m;
    cin>>m>>a;
    for(int b=0;b<a;b++){
        int f;
        cin>>f;
        objs.push_back(f);
    }

    for (int i = 0; i < a; i++){
        for (int e = m; e>=objs[i];e--){
            table[e]=max(table[e],table[e-objs[i]]+objs[i]);
        }
    }

    cout<<table[m];
    return 0;
}
