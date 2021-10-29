#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5, TB = sqrt(MAXn);

int n, q;
int mapa[MAXn * 2 + 10];
int arr[MAXn + 10];

set < int > num;
int cant[MAXn];

struct query{
    int l;
    int r;
    int id;
    bool operator < (const query &var) const {
        return (var.l/TB != l/TB ? var.l > l : var.r > r);
    }
}mo[MAXn];

void funt(int val, int k){
    if(mapa[val]){
        cant[mapa[val]]--;
        if(!cant[mapa[val]])
            num.erase(mapa[val]);
    }
    mapa[val] += k;
    if(!mapa[val]) return;
    num.insert(mapa[val]);
    cant[mapa[val]]++;
}

int sol[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>n;
        if(!n) return 0;
        cin>>q;
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
            arr[i] += MAXn;
        }
        for(int i = 0; i < q; i++){
            cin>>mo[i].l>>mo[i].r;
            mo[i].id = i;
        }
        sort(mo, mo + q);
        int l = 1;
        int r = 0;
        for(int i = 0; i < q; i++){
            int nl = mo[i].l;
            int nr = mo[i].r;
            while(r < nr) funt(arr[++r], 1);
            while(l < nl) funt(arr[l++], -1);
            while(r > nr) funt(arr[r--], -1);
            while(l > nl) funt(arr[--l], 1);
            sol[mo[i].id] = *num.rbegin();
        }
        for(int i = 0; i < q; i++){
            cout<<sol[i]<<"\n";
            sol[i] = 0;
        }
        fill(mapa + arr[1], mapa + arr[n] + 1, 0);
        num.clear();
        fill(cant, cant + n + 1, 0);
    }
    return 0;
}
