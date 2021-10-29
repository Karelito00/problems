#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int c,suma=1;
        cin>>c;
    for(int d=2;d<c;d++){
        if(c%d==0){
            suma+=d;
        }
    }
        if(suma<c)
            cout<<"Deficient\n";
            if(suma==c)
                cout<<"Perfect\n";
            if(suma>c)
                cout<<"Abundant\n";
}

    return 0;
}