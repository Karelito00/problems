#include <bits/stdc++.h>

using namespace std;
int sumadigit(string h){
    int suma=0;
    if(h[0]!='-'){
    for(int i=0;i<h.size();i++)
        suma+=(h[i]-'0');
    }else{
    for(int i=1;i<h.size();i++)
        suma+=(h[i]-'0');
    }
    return suma;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        cout<<sumadigit(s)<<"\n";
    }
    return 0;
}
