#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct node{
    int val;
    int abc[26];
    node(){
        val = 0;
        for(int i = 0; i <= 25; i++) abc[i] = -1;
    }
};

int ascii(char x){
    return x - 'a';
}

vector < node > box;
vector < node > no_at;

void insert_trie(string n, vector < node > &trie){
    int nodo = 0;
    int tm = n.size();
    for(int i = 0; i < tm; i++){
        int aux = ascii(n[i]);
        if(trie[nodo].abc[aux] == -1){
            trie[nodo].abc[aux] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].abc[aux];
        trie[nodo].val++;
    }
}

int query(int con, int nodo, int nt){
    if(nt == -1 || no_at[nt].val == 0)
        return con;
    int aux = 0;
    for(int i = 0; i <= 25; i++){
        if(box[nodo].abc[i] != -1)
            aux += query(con + 1, box[nodo].abc[i], no_at[nt].abc[i]);
    }
    return aux;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    box.push_back(node());
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        insert_trie(s, box);
    }
    no_at.push_back(node());
    for(int i = 0; i < m; i++){
        string s;
        cin>>s;
        insert_trie(s, no_at);
    }
    int sol = 0;
    for(int i = 0; i <= 25; i++){
        if(box[0].abc[i] != -1)
            sol += query(1, box[0].abc[i], no_at[0].abc[i]);
    }
    cout<<sol;
    return 0;
}
