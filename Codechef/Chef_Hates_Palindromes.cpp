#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int mini = INT_MAX;

string arr[] = {"", "a", "ab", "aab", "aabb", "aaabb", "aaabbb", "aaababb", "aaababbb"};
int arrl[] = {0, 1, 1, 2, 2, 3, 3, 3, 3};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        if(p == 1){
            cout<<n<<" ";
            for(int i = 0; i < n; i++) cout<<'a';
            cout<<"\n";
            continue;
        }
        if(p >= 3){
            cout<<1<<" ";
            int con = 0;
            for(int i = 0; i < n; i++){
                cout<<(char)(con + 'a');
                con++;
                if(con == p) con = 0;
            }
        }
        else{
            if(n <= 8){
                cout<<arrl[n]<<" "<<arr[n]<<"\n";
                continue;
            }
            string m = "bbabaa";
            cout<<"4 aaaa";
            int con = 0;
            for(int i = 4; i < n; i++){
                cout<<m[con];
                con++;
                if(con == (int)m.size()) con = 0;
            }
        }
        cout<<"\n";
    }
    return 0;
}
