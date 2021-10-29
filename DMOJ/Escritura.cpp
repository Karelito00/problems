#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e5 + 2;

struct nod{
    int abc[27];
    nod(){
        for(int i = 0; i <= 26; i++)
            abc[i] = -1;
    }
};

vector < nod > trie;

int ascii(char x){
    if(x == ' ')
        return 26;
    return x - 'a';
}

void insert_trie(string h){
    int nodo = 0;
    for(auto x: h){
        if(trie[nodo].abc[ascii(x)] == -1){
            trie[nodo].abc[ascii(x)] = trie.size();
            trie.push_back(nod());
        }
        nodo = trie[nodo].abc[ascii(x)];
    }
}

int query(string j){
    int nodo = trie[0].abc[ascii(j[0])];
    int sol = 0;
    for(int i = 1; i < (int)j.size(); i++){
        bool mark = true;
        for(int k = 0; k <= 26; k++){
            if(trie[nodo].abc[k] != -1 && ascii(j[i]) != k){
                mark = false;
                break;
            }
        }
        if(mark) sol++;
        nodo = trie[nodo].abc[ascii(j[i])];
    }
    return j.size() - sol;
}

string arr[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        trie.push_back(nod());
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            insert_trie(arr[i] + ' ');
        }
        double suma = 0;
        for(int i = 1; i <= n; i++)
            suma += query(arr[i]);
        cout<<fixed<<setprecision(2)<<suma / (double)n<<"\n";
        trie.clear();
    }
    return 0;
}
