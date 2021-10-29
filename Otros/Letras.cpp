#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int a, b, c, am, bm, cm;
string s, m;
int n;
char sol[5001];

bool funt(int n1){
    if(n1 == 1) a--;
    else if(n1 == 2) b--;
    else c--;
    if(a + b >= cm && a + c >= bm && b + c >= am)
        return true;
    if(n1 == 1) a++;
    else if(n1 == 2) b++;
    else c++;
    return false;
}

int main()
{
    freopen("igra.in","r",stdin);
    freopen("igra.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>s>>m;
    for(auto x: s){
        if(x == 'a') a++;
        else if(x == 'b') b++;
        else c++;
    }
    for(auto x: m){
        if(x == 'a') am++;
        else if(x == 'b') bm++;
        else cm++;
    }
    for(int i = 0; i < n; i++){
        if(m[i] == 'a'){
            am--;
            if(b && funt(2)) sol[i] = 'b';
            else{
                sol[i] = 'c';
                c--;
            }
        }
        else if(m[i] == 'b'){
            bm--;
            if(a && funt(1)) sol[i] = 'a';
            else{
                sol[i] = 'c';
                c--;
            }
        }
        else{
            cm--;
            if(a && funt(1)) sol[i] = 'a';
            else{
                sol[i] = 'b';
                b--;
            }
        }
    }
    cout<<sol;
    return 0;
}
