#include <bits/stdc++.h>
#define MAX 99999999

using namespace std;

int n,sol;
int abi[200001];
int num[200001];

void update(int pos, int val){
    while(pos <= n){
        abi[pos] = min( abi[pos], val );
        pos += pos & (-pos);
    }
}

int query(int pos){
    int best = MAX;
    while(pos>=1){
        best = min(best, abi[pos]);
        pos -= pos & (-pos);
    }
    return best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    fill(abi, abi+n, MAX);
    for(int i=1;i<=n;i++){
        update(num[i]+1,i);
        int in=query(num[i]);
        if(in!=MAX)
            sol=max(sol,i-in+1);
    }
    if(sol==0)
        cout<<-1;
    else
        cout<<sol;
    return 0;
}
