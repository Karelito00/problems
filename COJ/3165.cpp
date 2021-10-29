#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair < int , int > par;
int const MAXn = 5e3 + 2;

par arr[MAXn];
vector < par > pen;

bool up;
bool down;
par c;
int aux;

bool funt(par a, par b){
    c.f = a.f - b.f;
    c.s = a.s - b.s;
    if(c.f == 0){
        up = true;
        return false;
    }
    if(c.s == 0){
        down = true;
        return false;
    }
    aux = __gcd(c.f, c.s);
    return true;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i].f>>arr[i].s;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(funt(arr[i], arr[j]))
                pen.push_back(mp(c.f / aux, c.s / aux));
        }
    }
    if(up && down){
        cout<<"YES";
        return 0;
    }
    sort(all(pen));
    for(auto x: pen){
        par t = x;
        swap(t.f, t.s);
        t.f *= -1, t.s *= -1;
        if(t != x && binary_search(all(pen), t)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
