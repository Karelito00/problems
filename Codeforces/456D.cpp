#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sol(v) cout<<((v) ? "First" : "Second")

using namespace std;

int const MAXn = 1e5 + 400;

int ascii(char x){
    return x - 'a';
}

struct node{
    int abc[26];
    node(){
        for(int i = 0; i <= 25; i++)
            abc[i] = -1;
    }
};

vector < node > trie;
int lose[MAXn] , win[MAXn];

void insert_trie(string &s){
    int nodo = 0;
    for(auto x: s){
        int let = ascii(x);
        if(trie[nodo].abc[let] == -1){
            trie[nodo].abc[let] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].abc[let];
    }
}

void DFS(int v){
    win[v] = false;
    lose[v] = false;
    bool leaf = true;
    for(int i = 0; i < 26; i++){
        if(trie[v].abc[i] != -1){
            leaf = false;
            int to = trie[v].abc[i];
            DFS(to);
            win[v] |= !win[to];
            lose[v] |= !lose[to];
        }
    }
    if(leaf)
        lose[v] = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    trie.push_back(node());
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        insert_trie(s);
    }
    DFS(0);
    if(k == 1) sol(win[0]);
    else if(!win[0]) sol(0);
    else if(lose[0]) sol(1);
    else if(k % 2 == 1) sol(1);
    else sol(0);
    return 0;
}
