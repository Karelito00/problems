#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 10;

int arr[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        int l;
        cin>>l;
        vector < int > lis;
        int minm = INT_MAX;
        lis.push_back(1);
        for(int i = 2; i <= n; i++){
            int k = arr[i];
            if(k > arr[lis.back()]){
                lis.push_back(i);
                continue;
            }
            int li = 0, ri = lis.size();
            while(li < ri){
                int mit = (li + ri) >> 1;
                if(arr[lis[mit]] < k)
                    li = mit + 1;
                else
                    ri = mit;
            }
            lis[ri] = i;
        }
        for(int i = l - 1; i < (int)lis.size(); i++)
            minm = mn(minm, arr[lis[i]]);
        if(minm != INT_MAX)
            cout<<minm<<"\n";
        else
            cout<<-1<<"\n";
    }
    return 0;
}
