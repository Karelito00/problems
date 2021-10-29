#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define base 29

using namespace std;

typedef unsigned long long ull;
int const MAXl = 1e6 + 10;

int ascii(char l){
    return l - 'a';
}

struct node{
    int cant;
    int let[26];
    node(){
        for(int i = 0; i < 26; i++)
            let[i] = -1;
        cant = 0;
    }
};

vector < node > trie;

void push_trie(string &s){
    int nod = 0;
    for(auto x: s){
        if(trie[nod].let[ascii(x)] == -1){
            trie[nod].let[ascii(x)] = trie.size();
            trie.push_back(node());
        }
        nod = trie[nod].let[ascii(x)];
        trie[nod].cant++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    string s;
    trie.push_back(node());
    for(int i = 0; i < n; i++){
        cin>>s;
        push_trie(s);
    }
    while(q--){
        cin>>s;
        int nod = 0;
        for(auto x: s){
            nod = trie[nod].let[ascii(x)];
            if(nod == -1)
                break;
        }
        cout<<(nod != -1 ? trie[nod].cant : 0)<<"\n";
    }
    return 0;
}
