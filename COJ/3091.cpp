#include <bits/stdc++.h>

using namespace std;

long long z[35];
vector < long long > num1;
vector < long long > num2;
long long k;

vector < long long > suma1;
vector < long long > suma2;

void bit_mask(long long n,int vect){
    for(long long mask=1;mask<(1<<n);mask++){
        long long suma = 0;
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                if(vect == 1)
                    suma += num1[u];
                else
                    suma += num2[u];
            }
        }
        if(suma <= k){
            if(1 == vect)
                suma1.push_back(suma);
            else
                suma2.push_back(suma);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n>>k;
    for(int i=0;i<n/2;i++){
        long long h;
        cin>>h;
        num1.push_back(h);
    }
    for(int i=n/2;i<n;i++){
        long long h;
        cin>>h;
        num2.push_back(h);
    }
    bit_mask(n/2,1);
    bit_mask((n-(n/2)),2);
    sort(suma2.begin(),suma2.end());
    long long con = 0;
    for(int i=0;i<(int)suma1.size();i++){
        long long y = k - suma1[i];
        con += (upper_bound(suma2.begin(),suma2.end(),y) - suma2.begin());
    }
    cout<<con + (long long)suma1.size() + (long long)suma2.size();
    return 0;
}
