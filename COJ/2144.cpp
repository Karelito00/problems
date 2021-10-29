#include <bits/stdc++.h>

using namespace std;
int z[1010];
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int b,c,suma=0;
        string s;
        cin>>b>>c>>s;
        for(int h=0;h<b;h++){
        int x;
        cin>>x;
        z[h]=x;
        }
        sort(z,z+b);
        if(s=="regulate"){
            int h=b-1;
            while(c>0){
                suma+=z[h];
                c--;
                h--;
            }
        }
        else if(s=="irregular"){
            for(int g=0;g<c;g++){
                suma+=z[g];
            }
        }
        cout<<suma<<"\n";
    }

    return 0;
}