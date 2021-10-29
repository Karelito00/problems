#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e6 + 2;
long long ABI[MAXn];
int n, q;

void update(int pos, long long val){
    while(pos <= n){
        ABI[pos] += val;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long suma = 0;
    while(pos >= 1){
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
    for(int i = 1; i <= n; i++){
        int aux;
        cin>>aux;
        update(i, aux);
    }
    cin>>q;
    while(q--){
        char id;
        int a, b;
        cin>>id>>a>>b;
        if(id == 'q')
            cout<<query(b) - query(a - 1)<<"\n";
        else
            update(a, b);
    }
    return 0;
}
