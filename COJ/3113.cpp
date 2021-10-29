#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5;
pair < int , int > arr[MAXn + 10];

int funt(int y, int x, int y1, int x1){
    return abs(y - y1) + abs(x - x1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int suma = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i].f>>arr[i].s;
        if(i > 0)
            suma += funt(arr[i].f, arr[i].s, arr[i - 1].f, arr[i - 1].s);
    }
    int sol = suma;
    for(int i = 1; i < n - 1; i++)
        sol = mn(sol, suma - funt(arr[i].f, arr[i].s, arr[i - 1].f, arr[i - 1].s) - funt(arr[i].f, arr[i].s, arr[i + 1].f, arr[i + 1].s) + funt(arr[i + 1].f, arr[i + 1].s, arr[i - 1].f, arr[i - 1].s));
    cout<<sol;
    return 0;
}
