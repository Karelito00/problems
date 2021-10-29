#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

vector < pair < int , int > > arr;
set < pair < int , pair < int , int > > > kk;
int n, a, b, c;

void funt(int h, int x){
    for(int i = 1; i * i <= h; i++){
        if(h % i == 0){
            long long div1 = i, div2 = h / i;
            if(div1 <= a){
                if(div2 <= b && x <= c)
                    kk.insert(mp(div1, mp(div2, x)));
                if(div2 <= c && x <= b)
                    kk.insert(mp(div1, mp(x, div2)));
            }
            if(div1 <= b){
                if(div2 <= a && x <= c)
                    kk.insert(mp(div2, mp(div1, x)));
                if(div2 <= c && x <= a)
                    kk.insert(mp(x, mp(div1, div2)));
            }
            if(div1 <= c){
                if(div2 <= a && x <= b)
                    kk.insert(mp(div2, mp(x, div1)));
                if(div2 <= b && x <= a)
                    kk.insert(mp(x, mp(div2, div1)));
            }
        }
    }
}

int main()
{
    freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0)
                arr.push_back(mp(i, n / i));
        }
        sort(all(arr));
        for(auto x: arr){
            if(x.f > a) break;
            funt(x.s, x.f);
        }
        cout<<kk.size()<<"\n";
        kk.clear();
        arr.clear();
    }
    return 0;
}
