#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

bool criba[32001];
vector < int > num;
vector < int > prim;

int excl_incl(int n) {

    int total = 0;
    int e = (int)num.size();
    for(int mask=1;mask<(1<<e);mask++) {
        int mult = 1;
        for(int i=0;i<e;i++){
            if(mask&(1<<i))
                mult *= num[i];
        }
        if(__builtin_popcount(mask) & 1)
            total += n / mult;
        else
            total -= n / mult;
    }
    return n - total;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<1001;i++){
        if(!criba[i])
            prim.push_back(i);
        for(int j=i*2;j<1001;j+=i){
            criba[j] = true;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        int b = n;
        for(int i=0;i<(int)prim.size();i++){
            if(prim[i] > n)
                break;
            if(n % prim[i] == 0){
                num.push_back(prim[i]);
                while(n % prim[i] == 0){
                    n /= prim[i];
                }
            }
        }
        if(n != 1)
            num.push_back(n);
        cout<<excl_incl(b)<<"\n";
        num.clear();
    }
}
