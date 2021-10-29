#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5;

int ABI[MAXn];
int n;

void update(int pos){
    while(pos <= n){
        ABI[pos]++;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int suma = 0;
    while(pos >= 1){
        suma += ABI[pos];
        pos -= (pos&-pos);
    }
    return suma;
}

queue < int > cola;
int sol[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string gen, h;
    cin>>n>>gen>>h;
    for(int hh = 0, gg = 0; hh < n; hh++, gg++){
        while(!cola.empty() && gen[cola.front()] == h[hh]){
            int aux = query(cola.front() + 1);
            sol[cola.front()] = hh - aux;
            update(cola.front() + 1);
            cola.pop();
            hh++;
        }
        if(hh == n) break;
        while(gen[gg] != h[hh]){
            cola.push(gg);
            gg++;
        }
        update(gg + 1);
    }
    for(int i = 0; i < n; i++)
        cout<<sol[i]<<"\n";
    return 0;
}
