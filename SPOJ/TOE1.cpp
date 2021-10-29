#include <bits/stdc++.h>
#define base 5

using namespace std;

typedef unsigned long long ull;

struct state{
    char mat[3][3];
    state(){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) mat[i][j] = '.';
    }
};

unordered_map < ull , int > mapa;

ull hashing(state a){
    ull aux = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a.mat[i][j] == '.')
                aux = aux * base + 1;
            else if(a.mat[i][j] == 'O')
                aux = aux * base + 2;
            else
                aux = aux * base + 3;
        }
    }
    return aux;
}
state init;

bool revisa(state a){
    for(int i = 0; i < 3; i++){
        if(a.mat[i][0] == a.mat[i][1] && a.mat[i][2] == a.mat[i][0] && a.mat[i][0] != '.')
            return false;
    }
    for(int i = 0; i < 3; i++){
        if(a.mat[0][i] == a.mat[1][i] && a.mat[2][i] == a.mat[0][i] && a.mat[0][i] != '.')
            return false;
    }
    if(a.mat[0][0] == a.mat[1][1] && a.mat[2][2] == a.mat[0][0] && a.mat[0][0] != '.')
        return false;
    if(a.mat[0][2] == a.mat[1][1] && a.mat[2][0] == a.mat[1][1] && a.mat[1][1] != '.')
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init = state();
    ull k = hashing(init);
    mapa[k] = true;
    queue < pair < state , int > > cola;
    cola.push(make_pair(init, 0));
    while(!cola.empty()){
        state v = cola.front().first;
        state aux = v;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(aux.mat[i][j] == '.'){
                    if(cola.front().second % 2 == 0){
                        aux.mat[i][j] = 'X';
                        ull y = hashing(aux);
                        if(!mapa[y]){
                            mapa[y] = true;
                            if(revisa(aux))
                                cola.push(make_pair(aux, cola.front().second + 1));
                        }
                    }
                    else{
                        aux.mat[i][j] = 'O';
                        ull y = hashing(aux);
                        if(!mapa[y]){
                            mapa[y] = true;
                            if(revisa(aux))
                                cola.push(make_pair(aux, cola.front().second + 1));
                        }
                    }
                    aux.mat[i][j] = '.';
                }
            }
        }
        cola.pop();
    }
    int t;
    cin>>t;
    while(t--){
        state r;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                cin>>r.mat[i][j];
        }
        if(mapa[hashing(r)])
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
