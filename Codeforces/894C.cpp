#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e3 + 5;

int arr[MAXn];

vector < int > sol;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sol.push_back(arr[0]);
    int totgcd = arr[0];
    for(int i = 1; i < n; i++){
        if(binary_search(arr, arr + n, __gcd(arr[i], sol.back())) && binary_search(arr, arr + n, __gcd(arr[i], totgcd)))
            sol.push_back(arr[i]);
        else{
            cout<<-1;
            return 0;
        }
        sol.push_back(arr[0]);
    }
    cout<<sol.size()<<"\n";
    for(auto x: sol)
        cout<<x<<" ";
    return 0;
}
