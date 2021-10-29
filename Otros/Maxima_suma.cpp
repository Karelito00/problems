#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define par pair < int , int >

using namespace std;

int const MAXn = 1e5 + 10, TB = sqrt(MAXn);

long long arr[MAXn];
par B[TB + 10];
int n;

int query(int a, int b){
    int pri = 0, seg = 0;
    int BA = a/TB;
    for(; a/TB == BA && a <= b; a++){
        if(pri <= arr[a]){
            seg = pri;
            pri = arr[a];
        }
        else if(seg < arr[a])
            seg = arr[a];
    }
    int BB = b/TB;
    for(; b/TB == BB && b >= a; b--){
        if(pri < arr[b]){
            seg = pri;
            pri = arr[b];
        }
        else if(seg < arr[b])
            seg = arr[b];
    }
    BA++;
    for(; BA < BB; BA++){
        if(pri < B[BA].f){
            seg = pri;
            pri = B[BA].f;
            seg = mx(seg, B[BA].s);
        }
        else if(seg < B[BA].f){
            seg = B[BA].f;
        }
    }
    return pri + seg;
}

void update(int a, int b){
    int BA = a/TB;
    arr[a] = b;
    B[BA] = mp(0,0);
    int i = BA * TB;
    int fin = i + TB;
    for(; i < fin && i < n; i++){
        if(B[BA].f <= arr[i]){
            B[BA].s = B[BA].f;
            B[BA].f = arr[i];
        }
        else if(B[i/TB].s < arr[i])
            B[i/TB].s = arr[i];
    }
}

int main()
{
    /*freopen("msum.in","r",stdin);
    freopen("msum.out","w",stdout);*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
        if(B[i/TB].f <= arr[i]){
            B[i/TB].s = B[i/TB].f;
            B[i/TB].f = arr[i];
        }
        else if(B[i/TB].s < arr[i])
            B[i/TB].s = arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        int a, b;
        cin>>a>>b;
        if(x == 'Q'){
            cout<<query(a - 1, b - 1)<<"\n";
        }
        else{
            update(a - 1, b);
        }
    }
    return 0;
}

