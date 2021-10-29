#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int con=1;
    int num=0;
    while(a >= 0 && b >= 0){
        if(num % 2==0){
            a -= con;
        }
        else{
            b -= con;
        }
        con++;
        num++;
    }
    if(a<0)
        cout<<"Vladik";
    else
        cout<<"Valera";
    return 0;
}
