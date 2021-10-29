#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef unsigned long long ull;

ull fact[21];

unordered_map < int , string > mapa;

int arr1[70];
int arr2[70];

void funt(int n){
    fill(arr1,arr1 + 69, 0);
    fill(arr2,arr2 + 69, 0);
    int d2 = n / 10, d1 = n % 10;
    string h = mapa[n - 1];
    int tam = h.size() - 1;
    int tm = h.size();
    int rest = 0;
    for(; tam >= 0; tam--){
        arr1[(tm - tam) - 1] += (h[tam] - '0') * d1;
        rest = arr1[(tm - tam) - 1] / 10;
        arr1[(tm - tam) - 1] -= (rest * 10);
        arr1[(tm - tam)] += rest;
    }
    tam = h.size() - 1;
    for(; tam >= 0; tam--){
        arr2[(tm - tam)] += (h[tam] - '0') * d2;
        rest = arr2[tm - tam] / 10;
        arr2[(tm - tam)] -= (rest * 10);
        arr2[(tm - tam) + 1] += rest;
    }
    string new_s = "";
    for(int i = 0; i < 70; i++){
        arr1[i] += arr2[i];
        rest = arr1[i] / 10;
        arr1[i + 1] += rest;
        arr1[i] -= rest * 10;
    }
    for(int j = 69; j >= 0; j--)
        new_s.push_back(arr1[j] + '0');
    while(new_s[0] == '0')
        new_s = new_s.substr(1);
    mapa[n] = new_s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[1] = 1;
    for(int i = 2; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    ull num = fact[20];
    string p;
    while(num){
        p.push_back(num % 10 + '0');
        num /= 10;
    }
    reverse(all(p));
    mapa[20] = p;
    for(int i = 21; i <= 40; i++)
        funt(i);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n <= 20)
            cout<<fact[n]<<"\n";
        else
            cout<<mapa[n]<<"\n";
    }
    return 0;
}
