#include <bits/stdc++.h>

using namespace std;
bool primo (int n){
for(int y=3;y*y<=n;y++){
    if(n%y==0){
        return false;
    }
}
return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a;
        cin>>a;
        if(a==0)
            break;
        long long h=2;
        for(int g=3;g<=a;g+=2){
            if(primo(g)==1)
                h*=g;
        }
        cout<<h<<"\n";
    }
    return 0;
}
