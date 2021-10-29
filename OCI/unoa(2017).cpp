/**by Karelito**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b;
int k;
long long pascal[35][35];
ll sol(ll n){
    int bits=k;
    ll suma=0;
    for(int mask=30; mask>=0 && bits>=0;mask--){
        if(n&(1<<mask)){
            suma+=pascal[mask][bits];
            bits--;
        }
    }
    if(bits==0)
        suma++;
    return suma;

}
int main()
{
    //freopen("unoa.in","r",stdin);
    //freopen("unoa.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pascal[0][0]=1;
    for(int i=1;i<=30;i++){
        for(int j=0;j<=i;j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>k;
        cout<<sol(b)-sol(a-1)<<"\n";
    }
    return 0;
}
