#include <bits/stdc++.h>

using namespace std;

int otra(int n){
    int con=1;
    while(n!=1){
        if(n%2==0)
            n/=2;
        else
            n=(n*3)+1;
        con++;
    }
    return con;
}
int a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>a>>b){
        int ini=a,fin=b;
        int best=0;
        if(a>b)
            swap(a,b);
        for(int i=a;i<=b;i++)
            best=max(best,otra(i));
        cout<<ini<<" "<<fin<<" "<<best<<"\n";
    }
    return 0;
}
