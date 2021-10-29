#include <bits/stdc++.h>

using namespace std;
char z[]={'O','I','E'};
int main()
{
    int a,b,r=0;
    cin>>a>>b;
    for(int n=0;n<a;n++){
            cout<<z[r];
            int x=r+1;
            if(x==3)
                x=0;
            for(int g=0;g<b-1;g++){
                cout<<z[x];
                x++;
                if(x==3)
                    x=0;
            }
            r++;
            if(r==3)
                r=0;
            cout<<endl;
    }
    return 0;
}
