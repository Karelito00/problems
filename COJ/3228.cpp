#include <bits/stdc++.h>

using namespace std;

int const MAXn = 100001,
            TB = sqrt(MAXn);

int z[MAXn];
vector < int > B[TB+1];

int query(int a,int b,int num){
    int sol = 0;
    int Ba = a/TB;
    for(;a/TB<=Ba && a<=b;a++)
        if(z[a]<=num)
            sol++;
    int Bb = b/TB;
    for(;a/TB<Bb;a+=TB)
        sol += upper_bound(B[a/TB].begin(),B[a/TB].end(),num) - B[a/TB].begin();
    for(;a<=b;a++)
        if(z[a]<=num)
            sol++;
    return sol;
}

void update(int pos, int num){
    B[pos/TB][lower_bound(B[pos/TB].begin(),B[pos/TB].end(),z[pos]) - B[pos/TB].begin()] = num;
    z[pos] = num;
    sort(B[pos/TB].begin(),B[pos/TB].end());
}

int x, y, k;

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>z[i];
        B[i/TB].push_back(z[i]);
    }
    for(int i=0;i<TB;i++)
        sort(B[i].begin(),B[i].end());
    while(q--){
        char l;
        cin>>l;
        if(l == 'Q'){
            cin>>x>>y>>k;
            x--,y--;
            cout<<query(x,y,k)<<"\n";
        }
        else{
            cin>>x>>k;
            x--;
            update(x,k);
        }
    }
    return 0;
}
