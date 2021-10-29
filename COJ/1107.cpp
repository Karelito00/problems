#include <bits/stdc++.h>
#define MOD 800007
#define base 11

using namespace std;

int suma;
bool visited[800009];
pair < int , char > dist[800009];
struct karel{
    int arr[4][4];
};

int hashing(karel p){
    int tp = 0;
    for(int i=0;i<4;i++)
        tp = ((tp * base) + p.arr[0][i]) % MOD;
    for(int i=3;i>=0;i--)
        tp = ((tp * base) + p.arr[1][i]) % MOD;
    return tp;
}

void solution(int k){
    string s;
    while(dist[k].first != k){
        s.push_back(dist[k].second);
        k = dist[k].first;
    }
    int tam = s.size();
    cout<<tam<<"\n";
    for(int i=tam-1;i>=0;i--)
        cout<<s[i]<<"\n";
    exit(0);
}

void BFS(){

    karel z;
    for(int i=0;i<4;i++)
        z.arr[0][i] = i + 1;
    int con = 5;
    for(int i=3;i>=0;i--)
        z.arr[1][i] = con, con++;
    int yy = hashing(z);
    visited[yy] = true;
    queue < karel > cola;
    cola.push(z);
    dist[yy].first = yy;
    dist[yy].second = '0';
    if(yy == suma){
        cout<<0;
        exit(0);
    }
    while(!cola.empty()){
        karel v = cola.front();
        cola.pop();
        int jj = hashing(v);
        karel tt = v;
        for(int i=0;i<4;i++)
            swap(tt.arr[0][i],tt.arr[1][i]);
        int h = hashing(tt);
        if(!visited[h]){
            dist[h].first = jj;
            dist[h].second = 'A';
            if(h == suma)
                solution(h);
            visited[h] = true;
            cola.push(tt);
        }
        tt = v;
        for(int i=3;i>=1;i--)
            swap(tt.arr[0][i],tt.arr[0][i-1]), swap(tt.arr[1][i],tt.arr[1][i-1]);
        h = hashing(tt);
        if(!visited[h]){
            dist[h].first = jj;
            dist[h].second = 'B';
            if(h == suma)
                solution(h);
            visited[h] = true;
            cola.push(tt);
        }
        tt = v;
        swap(tt.arr[0][1],tt.arr[1][1]);
        swap(tt.arr[0][2],tt.arr[1][2]);
        swap(tt.arr[0][2],tt.arr[1][1]);
        h = hashing(tt);
        if(!visited[h]){
            dist[h].first = jj;
            dist[h].second = 'C';
            if(h == suma)
                solution(h);
            visited[h] = true;
            cola.push(tt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=8;i++){
        int n1;
        cin>>n1;
        suma = ((suma * base) + n1) % MOD;
    }
    BFS();
    return 0;
}
