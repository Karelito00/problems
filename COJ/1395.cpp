#include <bits/stdc++.h>

using namespace std;
int memort[10000000];
int con=0;
double suma=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int b=0;b<n;b++){
        int x;
        cin>>x;
        if(x>con){
            for(int y=con+1;y<=x;y++){
                suma+=log10(y);
                memort[y]=(int)suma+1;
            }
            con=x;
        }
        cout<<memort[x]<<"\n";
    }
    return 0;
}
