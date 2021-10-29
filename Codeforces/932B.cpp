#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

int const MAXn = 1e6 + 2;

int memo[MAXn];
int dist[MAXn][10];

int funt(int n){
    if(memo[n]) return memo[n];
    int x = n;
    int aux = 1;
    while(x > 0){
        if(x % 10) aux *= x % 10;
        x /= 10;
    }
    return memo[n] = funt(aux);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 9; i++)
        memo[i] = i;
    for(int i = 1; i <= MAXn - 2; i++){
        dist[i][funt(i)]++;
        for(int j = 1; j <= 9; j++)
            dist[i][j] += dist[i - 1][j];
    }
    int q;
    cin>>q;
    while(q--){
        int a, b, k;
        cin>>a>>b>>k;
        cout<<dist[b][k] - dist[a - 1][k]<<"\n";
    }
    return 0;
}
