#include <bits/stdc++.h>

using namespace std;

vector <int> nodos[50000];
char dist[50000];
int suma;

int main()
{
    freopen("decorate.in","r",stdin);
    freopen("decorate.out","w",stdout);
    int a,t;
    cin>>a>>t;
    for(int b=0;b<t;b++){
        int n1,n2;
        cin>>n1>>n2;
        n1--;
        n2--;
        nodos[n1].push_back(n2);
        nodos[n2].push_back(n1);
    }
    for(int j=0;j<a;j++)
        dist[j]='*';
    for(int i=0;i<a;i++){
        if(dist[i]=='*'){
            dist[i]='J';
            int con=1,cant=0;
            stack <int> pila;
            pila.push(i);
            while(!pila.empty()){
                int v=pila.top();
                pila.pop();
                cant++;
                for(int k=0;k<nodos[v].size();k++){
                    int to=nodos[v][k];
                    if(dist[to]=='*'){
                        pila.push(to);
                        if(dist[v]=='J'){
                            dist[to]='F';
                        }
                        else{
                            dist[to]='J';
                            con++;
                        }
                    }
                }
                for(int l=0;l<nodos[v].size();l++){
                    int to=nodos[v][l];
                    if(dist[to]==dist[v]){
                        cout<<-1;
                        exit(0);
                    }
                }
            }
            if(con<cant-con)
                suma+=(cant-con);
            else
                suma+=con;
        }
    }
        cout<<suma;
    return 0;
}
