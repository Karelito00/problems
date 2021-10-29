#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

unordered_map < int , char > let;

int cant[10];
vector < char > abc;

bool funt(int num){
    return num >= 65 && num <= 90;
}

void SOLVE(){
    sort(all(abc));
    for(auto x: abc)
        cout<<x;
    abc.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    let[65] = 'A';
    for(int i = 66; i <= 90; i++)
        let[i] = let[i - 1] + 1;
    int t;
    cin>>t;
    while(t--){
        string t;
        cin>>t;
        for(auto x: t)
            cant[x - '0']++;
        for(int i = 9; i >= 6; i--){
            if(!cant[i])
                continue;
            if(cant[i] > 1 && funt((i * 10) + i))
                abc.push_back(let[(i * 10) + i]);
            for(int j = i - 1; j >= 0; j--){
                if(cant[j]){
                    if(funt((i * 10) + j))
                        abc.push_back(let[(i * 10) + j]);
                    if(funt((j * 10) + i))
                        abc.push_back(let[(j * 10) + i]);
                }
            }
            cant[i] = 0;
        }
        for(int i = 0; i <= 5; i++)
            cant[i] = 0;
        SOLVE();
        cout<<"\n";
    }
    return 0;
}
