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
    int cant;
    node(){
        bit[0] = -1;
        bit[1] = -1;
        cant = 0;
    }
};

vector < node > trie;
int k;

void insert_trie(int n){
    int nodo = 0;
    for(int i = 30; i >= 0; i--){
        bool bt = n&(1<<i);
        if(trie[nodo].bit[bt] == -1){
            trie[nodo].bit[bt] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].bit[bt];
        trie[nodo].cant++;
    }
}

long long query(int n){
    int nodo = 0;
    long long sol1 = 0;
    for(int i = 30; i >= 0; i--){
        bool btn = (n & (1<<i));
        bool btk = (k & (1<<i));
        int v = trie[nodo].bit[!(btn ^ btk)];
        if(btk && v != -1)
            sol1 += trie[v].cant;
        if(trie[nodo].bit[btk ^ btn] == -1)
            return sol1;
        nodo = trie[nodo].bit[btk ^ btn];
    }
    return sol1;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        long long sol = 0, XORs = 0;
        trie.push_back(node());
        insert_trie(0);
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            XORs ^= x;
            sol += query(XORs);
            insert_trie(XORs);
        }
        cout<<sol<<"\n";
        trie.clear();
    }
    return 0;
}
