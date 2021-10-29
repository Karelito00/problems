#include <bits/stdc++.h>

using namespace std;
char z[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n,base;
        cin>>n>>base;
        int c=0;
        while(n>0){
                if(n%base==10)
                z[c]='A';
                else if(n%base==11)
                z[c]='B';
                else if(n%base==12)
                    z[c]='C';
                else if(n%base==13)
                    z[c]='D';
                else if(n%base==14)
                    z[c]='E';
                else if(n%base==15)
                    z[c]='F';
                else
            z[c]=(n%base)+'0';
            n=n/base;
            c++;
        }
        reverse(z,z+c);
        for(int u=0;u<c;u++)
            cout<<z[u];
        cout<<"\n";
    }
    return 0;
}
