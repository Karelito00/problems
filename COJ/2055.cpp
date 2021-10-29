#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

const int TAMA = 26;

int ascii(char l){
    return l - 'A';
}

struct node{
    int e[2],hij[TAMA];

    node(){
        for(int i = 0;i < TAMA;i++)
            hij[i] = -1;
        e[0] = e[1] = 0;
    }
};

vector < node > trie;

void insert_word(string &S,int team){
    int nod = 0;
    for(int i = 0; i < (int)S.size(); i++){
        if(trie[nod].hij[ascii(S[i])] == -1){
            trie[nod].hij[ascii(S[i])] = trie.size();
            trie.push_back(node());
        }
        nod = trie[nod].hij[ascii(S[i])];
        trie[nod].e[team]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        if(n == -1)
            break;

        trie.clear();

        string S;
        trie.push_back(node());
        for(int i = 1; i <= n; i++){
            cin>>S;
            insert_word(S,0);
        }
        for(int i = 1; i <= n; i++){
            cin>>S;
            insert_word(S,1);
        }
        long long sol = 0;
        for(auto x: trie)
            sol += mn(x.e[0],x.e[1]);
        cout<<sol<<"\n";
    }

    return 0;
}
