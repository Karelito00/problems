#include <bits/stdc++.h>

using namespace std;

long long z[14];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    long long m;
    while(cin>>n>>k>>m){
    vector < long long > divi;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    int con=0;
    for(int i=2;i*i<=m;i++){
        if(m%i==0 && i!=m/i){
           divi.push_back(i);
           divi.push_back(m/i);
           con+=2;
        }
        else if(m%i==0 && i==m/i){
            divi.push_back(i);
            con++;
        }
    }
    if(m!=1){
    divi.push_back(m);
    con++;
    }
    int cant=0;
    for(int mask=0; mask <(1<<n);mask++){
        long long suma=0;
        if(__builtin_popcount(mask)==k){
            for(int i=0;i<n;i++){
                if(mask&(1<<i))
                    suma+=z[i];
            }
            if(suma!=0){
            for(int j=0;j<con;j++){
                if(suma%divi[j]==0){
                    cant++;
                    break;
                }
            }
            }
        }
    }
    cout<<cant<<"\n";
    }
    return 0;
}
