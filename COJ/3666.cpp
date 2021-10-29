#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int const MAXn = 1e5 + 5,
            TB = sqrt(MAXn);
vector < long long > B[TB+5];
long long sum[TB+5];
int n, q;
long long arr[MAXn];
char x;

void update(int a, int b, long long z){
     int blockA = a/TB;
     for(int i = blockA * TB, con = 0; i < (blockA * TB) + TB && i < n; i++, con++){
        if(i >= a && i <= b)
            arr[i] += z;
        if(con < (int)B[blockA].size())
            B[blockA][con] = arr[i];
     }
     sort(B[blockA].begin(),B[blockA].end());
     if(b/TB == blockA) return;
     int blockB = b/TB;
     for(int i = blockB * TB, con = 0; i < (blockB * TB) + TB && i < n ;i++, con++){
        if(i <= b)
            arr[i] += z;
        if(con < (int)B[blockB].size())
            B[blockB][con] = arr[i];
     }
     sort(B[blockB].begin(),B[blockB].end());
     blockA++;
     for(;blockA<blockB;blockA++)
        sum[blockA] += z;
}

int query(int a, int b){
    long long bw = mx(arr[a]+sum[a/TB], arr[b]+sum[b/TB]);
    int sol = 0;
    int BA = (a/TB) + 1;
    for(;a/TB != BA && a <= b;a++)
        if(arr[a] + sum[a/TB] > bw) sol++;
    for(;a/TB < b/TB;a+=TB)
        sol += (int)B[a/TB].size() - (upper_bound(B[a/TB].begin(),B[a/TB].end(),bw - sum[a/TB]) - B[a/TB].begin());
    for(;a<=b;a++)
        if(arr[a] + sum[a/TB] > bw) sol++;
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        B[i/TB].push_back(arr[i]);
    }
    for(int i=0;i<n;i+=TB)
        sort(B[i/TB].begin(),B[i/TB].end());
    while(q--){
        int a, b;
        long long z;
        cin>>x>>a>>b;
        if(a > b)
            swap(a,b);
        a--, b--;
        if(x == 'U'){
            cin>>z;
            update(a,b,z);
        }
        else{
            cout<<query(a,b)<<"\n";
        }
    }
    return 0;
}
