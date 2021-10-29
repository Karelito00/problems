#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define base 67

using namespace std;

typedef unsigned long long ull;
int const MAXn = 1e5 + 2;

ull table[MAXn];
ull pww[MAXn];
vector < int > sol;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    pww[0] = 1;
    for(int i = 1; i <= n; i++)
        pww[i] = pww[i - 1] * base;
    for(int i = 1; i <= n; i++){
        char x;
        cin>>x;
        table[i] = (table[i - 1] * base) + (x - 'a' + 1);
    }
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ull hashing = table[i];
            bool yes = true;
            for(int j = i * 2; j <= n; j += i){
                if(table[j] - (table[j - i] * pww[i]) != hashing){
                    yes = false;
                    break;
                }
            }
            if(yes) sol.push_back(i);
            if(n / i != i && i != 1){
                int l = n / i;
                hashing = table[l];
                yes = true;
                for(int j = l * 2; j <= n; j += l){
                    if(table[j] - (table[j - l] * pww[l]) != hashing){
                        yes = false;
                        break;
                    }
                }
                if(yes) sol.push_back(l);
            }
        }
    }
    sort(all(sol));
    cout<<sol.size()<<"\n";
    for(auto x: sol)
        cout<<x<<" ";
    return 0;
}
