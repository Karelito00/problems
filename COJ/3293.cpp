#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long arr1[21];
long long arr2[21];
unordered_map < long long , long long > num;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long t;
    while(cin>>n>>t){
        int o1 = n / 2;
        for(int i = 0; i < o1; i++)
            cin>>arr1[i];
        int o2 = 0;
        for(int i = n / 2; i < n; i++, o2++)
            cin>>arr2[o2];
        for(int mask = 0; mask < (1<<o1); mask++){
            long long sum = 0;
            for(int i = 0; i < o1; i++)
                if(mask&(1<<i)) sum += arr1[i];
            num[sum]++;
        }
        long long sol = 0;
        for(int mask = 1; mask < (1<<o2); mask++){
            long long sum = 0;
            for(int i = 0; i < o2; i++)
                if(mask&(1<<i)) sum += arr2[i];
            if(num.find(t - sum) != num.end())
                sol += num[t - sum];
        }
        cout<<sol<<"\n";
        num.clear();
    }
    return 0;
}
