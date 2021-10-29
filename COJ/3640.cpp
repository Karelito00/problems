#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 1;
long long pascal[MAXn][4];
long long n;
char x;
unordered_map < long long , bool > cj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pascal[0][0] = 1;
    for(int i = 1; i < MAXn; i++){
        pascal[i][0] = 1;
        for(int j = 1; j <= mn(j,3); j++)
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
    int t;
    cin>>t;
    int par = 0, impar = 0;
    while(t--){
        cin>>x;
        if(x == 'i'){
            cin>>n;
            if(cj[n] == false){
                (n % 2 ? impar++ : par++);
                cj[n] = true;
            }
        }
        else if(x == 'r'){
            cin>>n;
            if(cj[n]){
                (n % 2 ? impar-- : par--);
                cj[n] = false;
            }
        }
        else{
            if(!par || par + impar < 3){
                cout<<"0\n";
                continue;
            }
            long long sol = 0;
            if(impar >= 2 && par >= 1)
                sol += (pascal[impar][2] * par);
            if(par >= 3)
                sol += pascal[par][3];
            cout<<sol<<"\n";
        }
    }
    return 0;
}
