#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int n,maxm;
int abi[1000001];
void update(int k,int val){
    while(k<=MAX){
        abi[k]+=val;
        k+=(k&-k);
    }
}

int query(int k){
    int suma=0;
    while(k>=1){
        suma+=abi[k];
        k-=(k&-k);
    }
    return suma;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        update(a,1);
        update(b+1,-1);
    }
    int best=0;
    for(int i=1;i<=MAX;i++){
        best=max(query(i),best);
    }
    printf("%d",best);
    return 0;
}
