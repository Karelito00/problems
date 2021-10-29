#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 2e5 + 10, TB = 447, MAXm = 1e6 + 10;

int arr[MAXn];
int f[MAXm];

struct query{
    int l;
    int r;
    int idd;
}mo[MAXn];

long long num;

void funt(int id, int k){
    num -= (long long)f[id] * f[id] * id;
    f[id] += k;
    num += (long long)f[id] * f[id] * id;
}

long long sol[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    for(int i = 1; i <= q; i++){
        cin>>mo[i].l>>mo[i].r;
        mo[i].idd = i;
    }
    sort(mo + 1, mo + q + 1,[](query& a, query& b){
        if(a.l / TB != b.l / TB)
            return a.l < b.l;
        return a.r > b.r;
    });
    int l = 1, r = 0;
    for(int i = 1; i <= q; i++){
        int nl = mo[i].l, nr = mo[i].r;
        while(r < nr) funt(arr[++r], 1);
        while(l < nl) funt(arr[l++], -1);
        while(r > nr) funt(arr[r--], -1);
        while(l > nl) funt(arr[--l], 1);
        sol[mo[i].idd] = num;
    }
    for(int i = 1; i <= q; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
