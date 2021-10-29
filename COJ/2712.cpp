#include <bits/stdc++.h>

using namespace std;
string z[1000];
string j[1000];
int main()
{
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string f;
        cin>>f;
        cin>>z[b];
    }
    int h;
    cin>>h;
    for(int p=0;p<h;p++){
        string f;
        cin>>f;
        cin>>j[p];
    }
    for(int o=0;o<h;o++){
            int c=0;
        for(int k=0;k<a;k++){
            if(z[k]==j[o])
            c++;
        }
    cout<<c<<endl;
    }
    return 0;
}
