#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e7 + 5;
vector < int > num;
bool criba[MAXn];

int funt(int n){
    int aux = 0;
    while(n > 0){
        aux = (aux * 10) + (n % 10);
        n /= 10;
    }
    return aux;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i = 2; i * i <= MAXn; i++){
        for(int j = i + i; j <= MAXn - 5; j += i)
            criba[j] = true;
    }
    for(int i = 2; i <= MAXn - 5; i++)
        if(!criba[i] && funt(i) == i) num.push_back(i);
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        int pos = (lower_bound(all(num), a) - num.begin()) - 1;
        cout<<(upper_bound(all(num), b) - num.begin() - 1) - pos<<"\n";
    }
    return 0;
}
