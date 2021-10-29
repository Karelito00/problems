#include <iostream>

using namespace std;

int z[100][100];
int cx[100];
int cy[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
    int a;
    cin>>a;
    if(a==0)
        break;
    for(int b=0;b<a;b++){
        for(int x=0;x<a;x++){
            cin>>z[b][x];
        }
    }
    int c1=0,c2=0;
    for(int h=0;h<a;h++){
            int suma=0,suma1=0;
        for(int y=0;y<a;y++){
            suma+=z[h][y];
            suma1+=z[y][h];
            }
            if(suma%2!=0){
             cx[c1]=h;
             c1++;
            }
            if(suma1%2!=0){
             cy[c2]=h;
             c2++;
            }
    }
    if(c1==0 && c2==0)
        cout<<"OK\n";
     else if(c1==1 && c2==1)
        cout<<"Change bit ("<<cx[0]+1<<","<<cy[0]+1<<")\n";
     else if(c1>1 || c2>1)
        cout<<"Corrupt\n";
}
    return 0;
}
