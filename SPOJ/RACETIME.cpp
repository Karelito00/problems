#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e5 + 5,
            TB = sqrt(MAXn);
int arr[MAXn];
vector < int > B[TB+5];

void update(int pos, int val){
    B[pos/TB][lower_bound(B[pos/TB].begin(),B[pos/TB].end(),arr[pos]) - B[pos/TB].begin()] = val;
    arr[pos] = val;
    sort(B[pos/TB].begin(),B[pos/TB].end());
}

int query(int a, int b, int val){
    int BA = a/TB;
    int sol = 0;
    for(;a/TB == BA && a <= b;a++)
        if(arr[a] <= val)
            sol++;
    int BB = b/TB;
    for(;a/TB<BB;a+=TB)
        sol += upper_bound(B[a/TB].begin(),B[a/TB].end(),val) - B[a/TB].begin();
    for(;a<=b;a++)
        if(arr[a] <= val)
            sol++;
    return sol;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        B[i/TB].push_back(arr[i]);
    }
    for(int i=0;i<n;i+=TB)
        sort(B[i/TB].begin(),B[i/TB].end());
    while(q--){
        char x;
        cin>>x;
        if(x == 'M'){
            int ind, val;
            cin>>ind>>val;
            update(ind-1,val);
        }
        else{
            int a, b, val;
            cin>>a>>b>>val;
            cout<<query(a-1,b-1,val)<<"\n";
        }
    }
    return 0;
}
