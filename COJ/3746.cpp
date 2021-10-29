#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

long long best[13];
long long arr[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n>>arr[1]>>arr[2]>>arr[3];
    if(n % 4 == 0){
        cout<<0;
        return 0;
    }
    best[1] = arr[1];
    best[2] = arr[2];
    best[3] = arr[3];
    for(int i = 4; i <= 11; i++)
        best[i] = (long long)99999999999999;
    for(int i = 2; i <= 11; i++){
        for(int j = 1; j < i && j <= 3; j++)
            best[i] = mn(best[i], best[i - j] + arr[j]);
    }
    cout<<mn(best[4 - (n % 4)], mn(best[8 - (n % 4)], best[12 - (n % 4)]));
    return 0;
}
