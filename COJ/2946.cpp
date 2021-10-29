#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int y;
        cin>>y;
        if(y%2==0){
            while(y%2==0){
                y=y/2;
            }

        }
        else{
                y=y*2;
            while(y%2!=0){
                y=y*2;
            }

        }
        cout<<y<<"\n";
    }
    return 0;
}