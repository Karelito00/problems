#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e6 + 2, MAXm = 1e5 + 2;

int cant[MAXn];
int arr[MAXm];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        cant[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        int aux = arr[i];
        int con = 0;
        for(int i = 1; i * i <= aux; i++){
            if(aux % i == 0){
                con += cant[i];
                if(aux / i != i)con += cant[aux / i];
            }
        }
        con--;
        cout<<con<<"\n";
    }
    return 0;
}
