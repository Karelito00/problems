#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin>>a;
    int con=0;
    for(int i=1;i<=500;i++){
        for(int j=i+1;j<=500;j++){
            if((j*j)-(i*i)==a)
                con++;
        }
    }
    cout<<con;
    return 0;
}
