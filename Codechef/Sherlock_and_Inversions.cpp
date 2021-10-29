#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 2e5 + 10, TB = sqrt(MAXn);

int arr1[MAXn];
int arr[MAXn];
int n;
long long ABI[MAXn];
unordered_map < int , queue < int > > mapa;

struct query{
    int l;
    int r;
    int id;
    bool operator < (const query &var) const {
        return (var.l/TB != l/TB ? var.l > l : var.r > r);
    }
}mo[MAXn];

void compress_coord(){
    for(int i = 1; i <= n; i++)
        mapa[arr1[i]].push(i);
    sort(arr1 + 1, arr1 + n + 1);
    int num = 1;
    int ant = arr1[1];
    arr[mapa[ant].front()] = 1;
    mapa[ant].pop();
    for(int i = 2; i <= n; i++){
        if(arr1[i] == ant){
            arr[mapa[ant].front()] = num;
            mapa[ant].pop();
            continue;
        }
        ant = arr1[i];
        arr[mapa[ant].front()] = ++num;
        mapa[ant].pop();
    }
}

long long num;

void update(int k, int val){
    while(k <= n){
        ABI[k] += val;
        k += (k&-k);
    }
}

long long query(int k){
    long long suma = 0;
    while(k >= 1){
        suma += ABI[k];
        k -= (k&-k);
    }
    return suma;
}

long long sol[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>arr1[i];
    compress_coord();
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>mo[i].l>>mo[i].r;
        mo[i].id = i;
    }
    sort(mo, mo + q);
    int l = 1, r = 0;
    for(int i = 0; i < q; i++){
        int nr = mo[i].r;
        int nl = mo[i].l;
        while(l < nl){
            num -= query(arr[l] - 1);
            update(arr[l++], -1);
        }
        while(r < nr){
            r++;
            num += (r - l) - (query(arr[r]));
            update(arr[r], 1);
        }
        while(r > nr){
            update(arr[r], -1);
            num -= (r - l) - (query(arr[r]));
            r--;
        }
        while(l > nl){
            l--;
            num += query(arr[l] - 1);
            update(arr[l], 1);
        }
        sol[mo[i].id] = num;
    }
    for(int i = 0; i < q; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
