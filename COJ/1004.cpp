#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        long long x,y;
        cin>>x>>y;
        if(x==y){
            if(x%2==0)
                cout<<"L\n";
            else
                cout<<"R\n";
        }
        else if(x>y){
            if(x%2==0 && y%2==0)
                cout<<"U\n";
            else if(x%2==1 && y%2==1)
                cout<<"D\n";
            else if(x%2==1 && y%2==0)
                cout<<"U\n";
            else if(x%2==0 && y%2==1)
                cout<<"D\n";
        }
        else if(x<y){
            if(x%2==0 && y%2==0)
                cout<<"L\n";
            else if(x%2==1 && y%2==1)
                cout<<"R\n";
            else if(x%2==1 && y%2==0)
                cout<<"R\n";
            else if(x%2==0 && y%2==1)
                cout<<"L\n";
        }
    }
    return 0;
}
