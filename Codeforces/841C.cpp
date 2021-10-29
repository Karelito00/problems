#include <bits/stdc++.h>

using namespace std;

int const MAXn = 2e5 + 10;
long long A[MAXn];
long long B[MAXn];
long long sol[MAXn];
long long arr[MAXn];
unordered_map < long long , long long > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>A[i];
    for(int i = 0; i < n; i++)
        cin>>B[i] , sol[i] = B[i];
    sort(A,A+n);
    sort(B,B+n);
    for(int i = 0; i < n; i++){
        mapa[B[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cout<<A[n - mapa[sol[i]] - 1]<<" ";
        mapa[sol[i]]--;
    }
    return 0;
}
