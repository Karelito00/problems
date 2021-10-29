#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update > ordered_set;

ordered_set X;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        char x;
        cin>>x;
        int n;
        cin>>n;
        if(x == 'I')
            X.insert(n);
        else if(x == 'D')
            X.erase(n);
        else if(x == 'K'){
            if((int)X.size() >= n)
                cout<<*X.find_by_order(n - 1)<<"\n";
            else
                cout<<"invalid\n";
        }
        else
            cout<<X.order_of_key(n)<<"\n";
    }
    return 0;
}
