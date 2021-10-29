#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

bool mark[60];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    if(n == 0)
        cout<<0;
    int con = 0;
    while(n != 0){
        if(n&1){
            mark[con] = true;
            n -= 1;
        }
        n /= -2;
        con++;
    }
    for(int i = con - 1;  i >= 0; i--)
        cout<<mark[i];
    return 0;
}
