#include <iostream>

using namespace std;

int main()
{
    int a,c=0;
    cin>>a;
    for(int y=0;y<a;y++){
        int g;
        cin>>g;
        while(g>0){
            int o=g%2;
            g=g/2;
            if(o==1)
                c++;
        }
    }
    cout<<c;

    return 0;
}
