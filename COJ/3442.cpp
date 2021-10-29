#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[500];
    cin>>a;
    int h=strlen(a);
    if(h%2==0){
    cout<<"error";
    }
    else{
    cout<<a<<endl;
    int v=h/2,space=1;
    for(int b=0;b<h-2;b++){
        for(int c=0;c<v;c++){
            cout<<a[c];
        }
        for(int y=0;y<space;y++){
            cout<<" ";
        }
        for(int p=v+space;p<h;p++){
            cout<<a[p];
        }
        cout<<endl;
        if(b<(h-2)/2){
        v+=-1;
        space+=2;
        }else{
            v+=1;
        space+=-2;
        }
    }
    cout<<a;
    }
    return 0;
}
