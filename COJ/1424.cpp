#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define mx(a,b) (a > b ? a : b)
#define dl double

using namespace std;

int const MAXn = (1<<16) + 10;

dl arr[17];
dl dp[MAXn];

struct par{
    int mk;
    dl area;
    bool operator < (const par &var) const {
        return var.mk > mk;
    }
};

vector < par > num;

bool funt(dl a, dl b, dl c){
    if(a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}

double area(double a, double b, double c){
    double semp = (a + b + c) / 2;
    return sqrt(semp*(semp - a)*(semp - b)*(semp - c));
}

int main()
{
    freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        for(int i = 0; i < n; i++){
            int Xor = 1<<i;
            for(int j = i + 1; j < n; j++){
                Xor ^= 1<<j;
                for(int k = j + 1; k < n; k++){
                    if(funt(arr[i], arr[j], arr[k]))
                        num.push_back(par{(Xor^(1<<k)), area(arr[i], arr[j], arr[k])});
                }
                Xor ^= 1<<j;
            }
        }
        sort(all(num));
        for(int mask = (1<<n) - 1; mask >= 7; mask--){
            for(int i = 0; i < (int)num.size() && num[i].mk <= mask; i++){
                if((mask|(num[i].mk)) == mask){
                    dp[(mask^(num[i].mk))] = mx(dp[(mask^(num[i].mk))], dp[mask] + num[i].area);
                }
            }
        }
        cout<<fixed<<setprecision(4)<<dp[0]<<"\n";
        fill(dp, dp + (1<<n) - 1, 0);
        num.clear();
    }
    return 0;
}
