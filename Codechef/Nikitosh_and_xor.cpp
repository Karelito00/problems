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

vector < node > trie1;
vector < node > trie2;

int const MAXn = 4e5 + 10;
long long arr[MAXn];
long long table1[MAXn];
long long table2[MAXn];

void trie_insert(int n, vector < node > &trie){
    int nodo = 0;
    for(int i = 30; i >= 0; i--){
        bool bt = n&(1<<i);
        if(trie[nodo].bit[bt] == -1){
            trie[nodo].bit[bt] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].bit[bt];
    }
}

long long query(int n, vector < node > &trie){
    int nodo = 0;
    long long num = n;
    for(int i = 30; i >= 0; i--){
        bool bt = n&(1<<i);
        if(trie[nodo].bit[abs(bt - 1)] != -1){
            if(abs(bt - 1))
                num ^= (1<<i);
            nodo = trie[nodo].bit[abs(bt - 1)];
        }
        else{
            if(bt)
                num ^= (1<<i);
            nodo = trie[nodo].bit[bt];
        }
    }
    return num;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    trie1.push_back(node());
    trie_insert(0,trie1);
    long long XOR = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        XOR ^= arr[i];
        trie_insert(XOR, trie1);
        table1[i] = mx(table1[i - 1], query(XOR, trie1));
    }
    XOR = 0;
    long long sol = 0;
    trie2.push_back(node());
    trie_insert(0,trie2);
    for(int i = n; i >= 1; i--){
        XOR ^= arr[i];
        trie_insert(XOR, trie2);
        table2[i] = mx(table2[i - 1], query(XOR, trie2));
    }
    for(int i = 1; i < n; i++)
        sol = mx(sol, table1[i] + table2[i + 1]);
    cout<<sol;
    return 0;
}
