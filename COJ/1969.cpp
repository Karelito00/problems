#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a;
    cin>>a;
    long long n=4;
    long long h=3;
    long long suma=10;
    while(1){
        suma=h+n+h;
        if(suma>a)
            break;
        h=suma;
        n++;
    }
    while(1){
       if(a-h-n>=1 && a<=h){
            suma=h;
            a-=(h+n);
            if(suma<=10){
                if(a==1 || a==4 || a==8)
                    cout<<'m';
                else
                    cout<<'o';
                exit(0);
            }
            n--;
            h=(h-n)/2;
       }
       else if(a>=h+n){
            suma=h;
            a-=(h+n);
            if(suma<=10){
                if(a==1 || a==4 || a==8)
                    cout<<'m';
                else
                    cout<<'o';
                exit(0);
            }
            n--;
            h=(h-n)/2;
       }
       else if(suma<=10){
                if(a==1 || a==4 || a==8)
                    cout<<'m';
                else
                    cout<<'o';
                exit(0);
        }
        else if(a-h>=1 &&a-h<=n){
            if(a-h==1)
                cout<<"m";
            else
                cout<<"o";
            exit(0);
        }
        while(h>=a){
            suma=h;
            n--;
            h=(suma-n)/2;
        }
    }
    return 0;
}

