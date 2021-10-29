#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct node{
    int bit[2];
    node(){
        bit[0] = -1;
        bit[1] = -1;
    }
};

vector < node > trie;

void trie_insert(long long n){
    int nodo = 0;
    for(long long i = 32; i >= 0; i--){
        bool bt = n&(1LL<<i);
        if(trie[nodo].bit[bt] == -1){
            trie[nodo].bit[bt] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].bit[bt];
    }
}

long long query(long long n){
    int nodo = 0;
    long long num = n;
    for(long long i = 32; i >= 0; i--){
        bool bt = n&(1LL<<i);
        if(trie[nodo].bit[abs(bt - 1)] != - 1){
            if(abs(bt - 1))
                num ^= (1LL<<i);
            nodo = trie[nodo].bit[abs(bt - 1)];
        }
        else{
            if(bt)
                num ^= (1LL<<i);
            nodo = trie[nodo].bit[bt];
        }
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long sol = 0;
        long long XOR = 0;
        trie.push_back(node());
        trie_insert(0);
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            XOR ^= x;
            trie_insert(XOR);
            sol = mx(sol, query(XOR));
        }
        cout<<sol<<"\n";
        trie.clear();
    }
    return 0;
}
