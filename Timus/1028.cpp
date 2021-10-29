#include <bits/stdc++.h>
#define s second
#define f first
#define all(v) (v).begin(), (v).end()

using namespace std;

int const MAXn = 15e3 + 2, TB = 123;

pair < int , int > arr[MAXn];
vector < int > B[TB];
int sol[MAXn];

int query(int a, int b, int val){
    int BA = a / TB;
    int con = 0;
    for(; a <= b && a / TB == BA; a++)
        if(arr[a].s <= val) con++;
    BA++;
    int BB = b / TB;
    for(; BA < BB; BA++)
        con += upper_bound(all(B[BA]), val) - B[BA].begin();
    for(; b >= a && b / TB == BB; b--)
        if(arr[b].s <= val) con++;
    return con;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i].f>>arr[i].s;
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        B[i / TB].push_back(arr[i].s);
    for(int i = 0; i < n; i += TB)
        sort(all(B[i / TB]));
    for(int i = 0; i < n; i++){
        int aux = query(0, i, arr[i].s);
        sol[aux - 1]++;
    }
    for(int i = 0; i < n; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
