#include <bits/stdc++.h>

using namespace std;

bool visited[20000];
int dist[20000];
int suma;
string solve(string k,int pos){
    if(k[pos]=='2') k[pos]='1';
    else k[pos]='2';
    if(pos>=0 && pos<3){
        if(pos-1>=0){
            if(k[pos-1]=='1') k[pos-1]='2';
            else k[pos-1]='1';
        }
        if(pos+1<=2){
            if(k[pos+1]=='2') k[pos+1]='1';
            else k[pos+1]='2';
        }
        if(k[pos+3]=='2') k[pos+3]='1';
        else k[pos+3]='2';
    }
    else if(pos>2 && pos<6){
        if(pos-1>=3){
            if(k[pos-1]=='1') k[pos-1]='2';
            else k[pos-1]='1';
        }
        if(pos+1<=5){
            if(k[pos+1]=='2') k[pos+1]='1';
            else k[pos+1]='2';
        }
        if(k[pos+3]=='2') k[pos+3]='1';
        else k[pos+3]='2';
        if(k[pos-3]=='2') k[pos-3]='1';
        else k[pos-3]='2';
    }
    else if(pos>=6 && pos<=8){
        if(pos-1>=6){
            if(k[pos-1]=='1') k[pos-1]='2';
            else k[pos-1]='1';
        }
        if(pos+1<=8){
            if(k[pos+1]=='2') k[pos+1]='1';
            else k[pos+1]='2';
        }
        if(k[pos-3]=='2') k[pos-3]='1';
        else k[pos-3]='2';
    }
    return k;
}
int hashing(string y){
    int sum=0;
    for(int i=0;i<(int)y.size();i++)
        sum=(sum*3)+(y[i]-'0');
    return sum;
}

int bfs(string s){
    queue <string> cola;
    cola.push(s);
    int ini=0;
    ini=hashing(s);
    dist[ini]=0;
    visited[ini]=true;
    while(!cola.empty()){
        string v=cola.front();
        cola.pop();
        int hashv=hashing(v);
        string m=v;
        for(int i=0;i<9;i++){
            m=solve(v,i);
            int has=hashing(m);
            if(visited[has]==false){
                dist[has]=dist[hashv]+1;
                cola.push(m);
                visited[has]=true;
                if(has==suma)
                    return dist[has];
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<9;i++){
        suma=(suma*3)+1;
    }
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char x;
                cin>>x;
                if(x=='.')
                    s.push_back('1');
                else
                    s.push_back('2');
            }
        }
        cout<<bfs(s)<<"\n";
        memset(visited,0,sizeof visited);
    }
    return 0;
}
