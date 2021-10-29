#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a;
        cin>>a;
        if(a==-1)
            break;
            int suma=0,con=0;
        for(int b=0;b<a;b++){
          int h;
          cin>>h;
          suma+=h;
          if(suma%100==0)
                con++;
        }
        cout<<con<<"\n";
    }
    return 0;
}
