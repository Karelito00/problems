#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct node{
    int abc[26];
    int con;
    node(){
        con = 0;
        for(int i = 0; i <= 25; i++)
            abc[i] = -1;
    }
};

vector < node > trie;

int ascii(char x){
    return x - 'a';
}

void insert_trie(string &k){
    int nodo = 0;
    for(int i = k.size() - 1; i >= 0; i--){
        int u = ascii(k[i]);
        if(trie[nodo].abc[u] == -1){
            trie[nodo].abc[u] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].abc[u];
        trie[nodo].con++;
    }
}

int query(string &h){
    int nodo = 0;
    for(int i = h.size() - 1; i >= 0; i--){
        int u = ascii(h[i]);
        if(trie[nodo].abc[u] == -1)
            return 0;
        nodo = trie[nodo].abc[u];
    }
    return trie[nodo].con;
}

int main()
{
    //freopen(".in","r",stdin);
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
    while(k--){
        string t;
        cin>>t;
        cout<<query(t)<<"\n";
    }
    return 0;
}
