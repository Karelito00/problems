#include <bits/stdc++.h>

using namespace std;

long long z[100001];
int ABI[100001];
long long arr[100001];
int n;

void update(int pos){
    while(pos<=n){
        ABI[pos]++;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int suma = 0;
    while(pos>=1){
        suma += ABI[pos];
        pos -= (pos&-pos);
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z[i];
        arr[i] = z[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        z[i] = lower_bound(arr,arr+n,z[i]) - arr + 1;
    for(int i=0;i<n;i++){
        update(z[i]);
        cout<<query(z[i])<<"\n";
    }
    return 0;
}
