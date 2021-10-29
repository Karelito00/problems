#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

int tabla[MAX];
int n,k,q;
int ot[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        int a1,b1;
        cin>>a1>>b1;
        tabla[a1]++;
        tabla[b1+1]--;

    }
    for(int i=1;i<=200000;i++){
        tabla[i] += tabla[i-1];
        if(tabla[i]>=k)
            ot[i]++;
        ot[i]+=ot[i-1];
    }
    for(int i=0;i<q;i++){
        int a1,b1;
        cin>>a1>>b1;
        cout<<ot[b1] - ot[a1-1]<<"\n";
    }
    return 0;
}
