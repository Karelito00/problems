#include <bits/stdc++.h>

using namespace std;
int distancia[64];
int z[8][8];
string mat[8][8];
vector <int> nodos[64];
queue <int> cola;
int mx[]={1,-1,-2,-2,-1,1,2,2};
int my[]={2,2,1,-1,-2,-2,-1,1};
void make_table(){
    int c=0;
    for(int u=0;u<8;u++){
        for(int n=0;n<8;n++){
            z[u][n]=c;
            c++;
        }
    }
    for(int i=0;i<8;i++){
        for(int p=0;p<8;p++){
            for(int g=0;g<8;g++){
                if(i+mx[g]>=0 && i+mx[g]<8 && p+my[g]>=0 && p+my[g]<8)
                    nodos[z[i][p]].push_back(z[i+mx[g]][p+my[g]]);
            }
        }
    }
    char j='8';
    char l='a';
    int prueba=8;
    for(int u=0;u<8;u++){
        for(int n=0;n<8;n++){
            string t;
            l=n+'a';
            t.push_back(l);
            t.push_back(j);
            mat[u][n]=t;
        }
        prueba--;
        j=prueba+'0';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_table();
    while(1){
        string s,n;
        cin>>s>>n;
        if(s=="##" && n=="##")
            break;
            int inicio=0,fin=0;
    for(int j=0;j<8;j++){
    for(int k=0;k<8;k++){
         if(mat[j][k]==s)
           inicio=z[j][k];
         if(mat[j][k]==n)
            fin=z[j][k];
    }
    }
    vector <bool> visited(64);
    cola.push(inicio);
    visited[inicio]=true;
    while(!cola.empty()){
        int V=cola.front();
        cola.pop();
        visited[V]=true;
        for(int h=0;h<nodos[V].size();h++){
                int to=nodos[V][h];
            if(visited[to]==false){
                visited[to]=true;
                cola.push(to);
                distancia[to]=distancia[V]+1;
            }
        }
    }
    cout<<"To get from "<<s<<" to "<<n<<" takes "<<distancia[fin]<<" knight moves.\n";
     memset(distancia,0,sizeof distancia);
    }
    return 0;
}
