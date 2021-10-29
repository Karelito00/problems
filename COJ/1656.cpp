#include <bits/stdc++.h>

using namespace std;
int table[45001];
int z[501];
int main()
{
    int m,b;
    cin>>m>>b;
    for(int i=0;i<b;i++){
        cin>>z[i];
    }
    for(int i=0;i<b;i++){
        for(int j=m;j>=z[i];j--){
            if(i==0)
                table[j]=z[i];
            else
                table[j]=max(table[j],table[j-z[i]]+z[i]);
        }
    }
    cout<<table[m];
    return 0;
}
