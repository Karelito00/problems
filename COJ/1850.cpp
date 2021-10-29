#include <bits/stdc++.h>

using namespace std;

long long table[1000000];
int a;
int query(int k){
    int suma=0;
    while(k>=1){
        suma=((suma+table[k])%10000);
        k-=(k&-k);
    }
    return suma;
}

void update(int k,int val){
    while(k<=a){
        table[k]=(table[k]+val)%10000;
        k+=(k&-k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u,q;
    cin>>a>>u>>q;
    for(int y=0;y<q+u;y++){
        int num,q1,q2;
        cin>>num>>q1>>q2;
        if(num==1){
            if(q1-1>=1)
                update(q1-1,q2);
            if(q1+1<=a)
                update(q1+1,q2);
            update(q1,q2*2);
        }
        else
        cout<<(query(q2)-query(q1-1)+10000)%10000<<"\n";
    }
    return 0;
}
