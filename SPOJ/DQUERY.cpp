#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXq = 2e5 + 10, MAXn = 3e4 + 10, MAXm = 1e6 + 10;
int const TB = sqrt(MAXn);

int f[MAXm];
int arr[MAXn];

struct query{
    int l;
    int r;
    int id;
}mo[MAXq];

int num;

void funt(int val, int k){
    if(k == 1){
        if(!f[val]) num++;
        f[val]++;
        return;
    }
    f[val]--;
    if(!f[val]) num--;
}

int sol[MAXq];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>mo[i].l>>mo[i].r;
        mo[i].id = i;
    }
    sort(mo, mo + q, [](query& a, query& b){return (a.l / TB != b.l / TB ? a.l < b.l : a.r < b.r);});
    int l = 1;
    int r = 0;
    for(int i = 0; i < q; i++){
        int nl = mo[i].l;
        int nr = mo[i].r;
        while(r < nr) funt(arr[++r], 1);
        while(l < nl) funt(arr[l++], -1);
        while(r > nr) funt(arr[r--], -1);
        while(l > nl) funt(arr[--l], 1);
        sol[mo[i].id] = num;
    }
    for(int i = 0; i < q; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
