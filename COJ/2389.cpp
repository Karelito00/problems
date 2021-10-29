#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 50000, TB = sqrt(MAXn);

struct var{
    int val;
    int ii;
    bool operator < (const var& var1) const {
        return var1.val < val;
    }
};

priority_queue < var > cola;
vector < int > arr;
unordered_map < int , int > mapa;

struct mo{
    int a;
    int b;
    bool operator < (const mo &var) const {
        return (var.a/TB != a/TB ? var.a > a : var.b > b);
    }
}query[MAXn / 2];

struct qq{
    int a1;
    int b1;
    bool operator < (const qq &var) const {
        return (var.a1 != a1 ? var.a1 > a1 : var.b1 < b1);
    }
}arr2[MAXn / 2];

int con;

void upd(int num, int ff){
    mapa[num] += ff;
    if(ff == 1 && mapa[num] == 2) con++;
    else if(ff == -1 && mapa[num] == 1) con--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    arr.push_back(0);
    for(int i = 1; i <= n; i++)
        cin>>arr2[i].a1>>arr2[i].b1;
    sort(arr2 + 1, arr2 + n + 1);
    for(int i = 1; i <= n; i++){
        int a = arr2[i].a1, b = arr2[i].b1;
        cola.push(var{b, i});
        while(cola.top().val < a){
            arr.push_back(cola.top().ii);
            query[cola.top().ii].b = arr.size() - 1;
            cola.pop();
        }
        arr.push_back(i);
        query[i].a = arr.size() - 1;
    }
    while(!cola.empty()){
        arr.push_back(cola.top().ii);
        query[cola.top().ii].b = arr.size() - 1;
        cola.pop();
    }
    sort(query + 1, query + n + 1);
    int sol = 0;
    int l = 1, r = 0;
    for(int i = 1; i <= n; i++){
        int nl = query[i].a;
        int nr = query[i].b;
        while(l < nl) upd(arr[l++], -1);
        while(r < nr) upd(arr[++r], 1);
        while(l > nl) upd(arr[--l], 1);
        while(r > nr) upd(arr[r--], -1);
        sol = mx(sol, con - 1);
    }
    cout<<sol;
    return 0;
}
