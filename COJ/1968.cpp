#include <bits/stdc++.h>
#define MAX 99999999
#define mn(a,b) (a < b ? a : b)

using namespace std;
typedef pair < int , int > pii;
int z[5];
map < int , int > mapa;
int mat[6][10000];
vector < pii > adya[10000];
int main()
{
    int a,m,c;
    cin>>a>>m>>c;
    for(int i=0;i<c;i++){
        cin>>z[i];
        z[i]--;
        mapa[z[i]] = i;
        for(int k=0;k<a;k++){
            mat[i][k]=MAX;
            if(k==z[i])
                mat[i][k]=0;
        }
    }
    for(int k=0;k<m;k++){
        int n1,n2,peso;
        cin>>n1>>n2>>peso;
        n1--,n2--;
        adya[n1].push_back(make_pair(n2,peso));
        adya[n2].push_back(make_pair(n1,peso));
    }
    priority_queue < pii , vector <pii> , greater <pii> > cola;
    for(int j=0;j<c;j++){
        cola.push(make_pair(0,z[j]));
        while(!cola.empty()){
            int n=cola.top().second,peso=cola.top().first;
            cola.pop();
            if(mat[j][n]>=peso){
                for(int k=0;k<adya[n].size();k++){
                    int to=adya[n][k].first;
                    int w=adya[n][k].second;
                    if(mat[j][n] + w < mat[j][to]){
                        mat[j][to]=mat[j][n]+w;
                        cola.push(make_pair(mat[j][to],to));
                    }
                }
            }

        }
    }
    sort(z,z+c);
    int fact = 1;
    for(int i = 2; i <= c; i++) fact *= i;
    int cant = 0, sol = MAX;
    int ini = 0, fin = 0;
    do{
        ini = z[0];
        fin = z[c - 1];
        cant++;
        int suma = 0;
        for(int i = 0; i < c - 1; i++){
             suma += mat[mapa[z[i]]][z[i + 1]];
        }
        for(int i = 0; i < a; i++){
            if(mapa.find(i) != mapa.end())
                continue;
            sol = mn(sol, mat[mapa[ini]][i] + mat[mapa[fin]][i] + suma);
        }
        if(cant * 2 >= fact) break;
    }while(next_permutation(z,z+c));
    cout<<sol;
    return 0;
}
