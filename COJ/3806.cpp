#include <bits/stdc++.h>

using namespace std;

int ulam[10001];
int mapa[10000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=4;i++){
        for(int j=i+1;j<=4;j++){
            mapa[i+j]++;
        }
    }
    ulam[1] = 1;
    ulam[2] = 2;
    ulam[3] = 3;
    ulam[4] = 4;
    int ulti = 5;
    for(int k = 5;k<=10000;k++){
        while(1){
            if(mapa[ulti] == 1){
                ulam[k] = ulti;
                ulti++;
                break;
            }
            ulti++;
        }
        for(int i=k-1;i>=1;i--){
            mapa[ulam[k]+ulam[i]]++;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ulam[n]<<"\n";
    }
    return 0;
}
