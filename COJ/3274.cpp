#include <bits/stdc++.h>

using namespace std;
bool primo(int n){
    if(n%2==0)
        return false;
for(int j=3;j*j<=n;j+=2)
    if(n%j==0)
    return false;
return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    int c;
    cin>>a;
    for(int b=0;b<a;b++){
        int h;
        cin>>h;
        if(h%2==0)
         c=1;
        else
        c=0;
        for(int k=3;k<=h;k++){
            if(primo(k)==1){
                if(h%k==0){
                    c++;
            }
            }
        }
        cout<<c<<"\n";
        c=0;
    }
    return 0;
}