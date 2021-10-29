#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int g;
    cin>>g;
    for(int u=0;u<g;u++){
    string s;
    cin>>s;
    int suma=0,n;
    for(int y=0;y<s.size();y++)
        suma+=s[y]-'0';
        int k=s.size()-1;
        n=(((s[k-2]-'0')*100)+((s[k-1]-'0')*10)+(s[k]-'0'))*10;
        int l=suma+n;
        if(l<=1000){
            while(l<=1000){
                l+=1000;
            }
            cout<<l<<"\n";
        }
        else if(l>=10000){
            int o=0;
            int z[50];
            while(l>0){
                int r=l%10;
                z[o]=r;
                l=l/10;
                o++;
            }
            for(int u=o-2;u>=0;u--)
                cout<<z[u];
            cout<<"\n";
        }
        else
            cout<<l<<"\n";
    }
    return 0;
}
