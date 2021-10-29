#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int ascii(char x){
    return x - '0';
}

struct node{
    int num[10];
    node(){
        for(int i = 0; i <= 9; i++)
            num[i] = -1;
    }
};

vector < node > trie;

void insert_trie(string &k){
    int nodo = 0;
    for(int i = 0; i < (int)k.size(); i++){
        int u = ascii(k[i]);
        if(trie[nodo].num[u] == -1){
            trie[nodo].num[u] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].num[u];
    }
}

bool query(string &k){
    int nodo = 0;
    bool yes = false;
    bool mayor = false;
    for(int j = 0; j < (int)k.size(); j++){
        int u = ascii(k[j]);
        if(trie[nodo].num[u] == -1){
            bool aux = true;
            for(int i = 0; i <= 9; i++)
                if(trie[nodo].num[i] != -1){
                    aux = false;
                    break;
                }
            if(aux) yes = true;
            mayor = true;
            break;
        }
        nodo = trie[nodo].num[u];
    }
    if(mayor) return yes;
    return true;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int u = 1; u <= t; u++){
        int n;
        cin>>n;
        trie.push_back(node());
        bool sol = false;
        for(int i = 1; i <= n; i++){
            string s;
            cin>>s;
            if(i != 1 && !sol){
                if(query(s))
                    sol = true;
            }
            if(!sol)
                insert_trie(s);
        }
        cout<<"Case "<<u<<": "<<(sol ? "NO" : "YES")<<"\n";
        trie.clear();
    }
    return 0;
}
