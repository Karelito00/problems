#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = (1<<10) + 2;

long long ABI[MAXn][MAXn];
int n;

void update(int a, int b, long long val){
    for(; a <= n; a += (a&-a)){
        for(int i = b; i <= n; i += (i&-i))
            ABI[a][i] += val;
    }
}

long long query(int a, int b){
    long long sol = 0;
    for(; a > 0; a -= (a&-a)){
        for(int i = b; i > 0; i -= (i&-i))
            sol += ABI[a][i];
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        short type;
        cin>>type;
        if(type == 0)
            cin>>n;
        else if(type == 1){
            int a, b;
            long long val;
            cin>>a>>b>>val;
            a++, b++;
            update(a, b, val);
        }
        else if(type == 2){
            int a1, b1, a2, b2;
            cin>>a1>>b1>>a2>>b2;
            a1++, b1++, a2++, b2++;
            cout<<query(a2, b2) - query(a1 - 1, b2) - query(a2, b1 - 1) + query(a1 - 1, b1 - 1)<<"\n";
        }
        else
            break;
    }
    return 0;
}
