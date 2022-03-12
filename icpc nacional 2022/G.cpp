#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
typedef long long ll;

using namespace std;

int const MAXn = 2e5 + 2, MOD = 1e9 + 7;

struct node {
    ll state[2];
    ll dp;
    node() {
        dp = 0;
        state[0] = state[1] = -1; 
    }
};

vector < node > trie;

ll query(int val, int k) {
    ll sol = 0;
    int nod = 0;
    int sum = 0;
    for(int i = 20; i >= 0; i--) {
        bool tv = val & (1 << i);
        bool tk = k & (1 << i);
        if(!tk) {
            nod = trie[nod].state[tv];
        }
        else {
            sum += (1 << i);
            int aux_nod = trie[nod].state[tv];
            if(aux_nod != -1)
                sol = (sol + trie[aux_nod].dp) % MOD;
            nod = trie[nod].state[!tv];
        }
        if(nod == -1)
            break;
    }
    if(nod != -1 && sum < k)
        sol = (sol + trie[nod].dp) % MOD;
    return sol;
}

void update(int val, ll aux) {
    int nod = 0;
    for(int i = 20; i >= 0; i--) {
        bool t = val & (1 << i);
        if(trie[nod].state[t] == -1) {
            trie[nod].state[t] = trie.size();
            trie.push_back(node());
        }
        nod = trie[nod].state[t];
        trie[nod].dp = (trie[nod].dp + aux) % MOD;
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    trie.push_back(node());
    for (int i = 1; i <= n; i++) {
        int val;
        cin>>val;
        if(n == 1) {
            cout<< 1 <<"\n";
            break;
        }
        if(i == 1) {
            update(val, 1);
            continue;
        }
        ll aux = query(val, k);
        update(val, aux);
        if(i == n) {
            cout<< aux <<"\n";
        }
    }
    return 0;
}
