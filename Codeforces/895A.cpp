#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 370;

int arr[370];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int suma = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        suma += arr[i];
    }
    int sol = INT_MAX;
    for(int i = 1; i <= n; i++){
        int con = 0;
        int aux = 0;
        for(int j = 0; j < n; j++){
            int punt = j;
            while(con < i){
                aux += arr[punt];
                con++;
                punt++;
                if(punt == n) punt = 0;
            }
            sol = mn(sol, abs((suma - aux) - aux));
            aux = 0;
            con = 0;
        }
    }
    cout<<sol;
    return 0;
}
