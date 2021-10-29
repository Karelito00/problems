#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 5;

bool imp[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 5; i <= MAXn - 2; i += 4){
        imp[i] = true;
        imp[i + 1] = true;
    }
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>k>>n;
        if(n == 2 || n == 3){
            cout<<"impossible\n";
            continue;
        }
        string sol(n, '0');
        if(n == 4){
            if(k == 2)
                sol[0] = sol[2] = '1';
            else if(k == 4)
                sol[0] = sol[1] = '1';
            else{
                cout<<"impossible\n";
                continue;
            }
            sol[k - 1] = '2';
            cout<<sol<<"\n";
            continue;
        }
        if((imp[n] && k % 2 == 0) || (!imp[n] && k&1)){
            cout<<"impossible\n";
            continue;
        }
        if(k == 1){
            int dif = 1;
            sol[n - 1] = '1';
            for(int i = n - 2; i >= 3; i -= 2){
                if(dif < 2){
                    sol[i - 1] = '1';
                    dif++;
                }
                else{
                    sol[i - 2] = '1';
                    dif--;
                }
            }
            if(n % 2){
                sol[1] = '1';
                sol[2] = '0';
            }
            sol[0] = '2';
            cout<<sol<<"\n";
            continue;
        }
        else{
            long long set1 = 0;
            long long set2 = 0;
            set1 = (k != n ? n : n - 1);
            set2 = (set1 - 1 != k ? set1 - 1 : set1 - 2);
            sol[set1 - 1] = '1';
            long long may = set1;
            long long men = set2;
            for(int i = set2 - 1; i >= 3; i = men - 1){
                may = (i == k ? i - 1 : i);
                men = (may - 1 == k ? may - 2 : may - 1);
                if(set1 - set2 == 0 || set1 - set2 == 1){
                    if(may - men == 2){
                        set1 += men;
                        sol[men - 1] = '1';
                        set2 += may;
                    }
                    else{
                        set2 += men;
                        sol[may - 1] = '1';
                        set1 += may;
                    }
                }
                else if(set2 - set1 == 1){
                    set1 += may;
                    sol[may - 1] = '1';
                    set2 += men;
                }
                else if(set1 - set2 >= 2){
                    if(may - men == 2){
                        set1 += men;
                        sol[men - 1] = '1';
                        set2 += may;
                    }
                    else{
                        set1 += men;
                        sol[men - 1] = '1';
                        set2 += may;
                    }
                }
            }
            if(men >= 3 && k >= 3){
                if(set1 < set2){
                    set1 += 2, set2 += 1;
                    sol[1] = '1';
                }
                else{
                    sol[0] = '1';
                    set1 += 1, set2 += 2;
                }
            }
            if(n % 2 == 0 && set1 != set2)
                sol[0] = (set1 < set2 ? '1' : '0');
            if(n&1){
                if(set1 != set2)
                    swap(sol[may - 1], sol[men - 1]);
            }
            sol[k - 1] = '2';
            cout<<sol<<"\n";
        }
    }
    return 0;
}
