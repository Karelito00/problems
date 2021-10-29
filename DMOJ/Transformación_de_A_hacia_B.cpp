#include <bits/stdc++.h>

using namespace std;

unordered_map < long long , int > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin>>a>>b;
    mapa[a] = -1;
    queue < int > cola;
    cola.push(a);
    while(!cola.empty()){
        int v = cola.front();
        cola.pop();
        if(v * 10 + 1 <= b){
            if(mapa.find(v * 10 + 1) == mapa.end()){
                mapa[v * 10 + 1] = v;
                cola.push(v * 10 + 1);
            }
        }
        if(v * 2 <= b){
            if(mapa.find(v * 2) == mapa.end()){
                mapa[v * 2] = v;
                cola.push(v * 2);
            }
        }
    }
    vector < int > sol;
    if(mapa.find(b) == mapa.end()){
        cout<<"NO";
        return 0;
    }
    while(mapa[b] != -1){
        sol.push_back(b);
        b = mapa[b];
    }
    sol.push_back(b);
    cout<<"YES\n"<<sol.size()<<"\n";
    for(int i = sol.size() - 1; i >= 0; i--)
        cout<<sol[i]<<" ";
    return 0;
}
