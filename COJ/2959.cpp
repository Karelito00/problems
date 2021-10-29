#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

const int MAXn = 1e5 + 10;

struct par{
    int x, y;
    bool operator < (const par &var) const {
        return (var.x != x ? var.x > x : var.y < y);
    }
}arr[MAXn];
vector < int > lis;

bool funt(int x , int y, int tox, int toy){
    if(tox >= x && y >= toy) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i].x>>arr[i].y;
        sort(arr, arr + n);
        lis.push_back(0);
        for(int i = 1; i < n; i++){
            int ini = 0, fin = lis.size() - 1;
            if(funt(arr[lis[fin]].x, arr[lis[fin]].y, arr[i].x, arr[i].y)){
                lis.push_back(i);
                continue;
            }
            while(ini < fin){
                int mid = (ini + fin) >> 1;
                if(!funt(arr[lis[mid]].x, arr[lis[mid]].y, arr[i].x, arr[i].y))
                    fin = mid;
                else
                    ini = mid + 1;
            }
            lis[ini] = i;
        }
        cout<<lis.size()<<"\n";
        lis.clear();
    }
    return 0;
}
