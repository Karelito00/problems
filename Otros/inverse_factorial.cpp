#include <bits/stdc++.h>

using namespace std;
string z[10]={"1","2","6","24","120","720","5040","40320","362880"};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int y=0;y<9;y++){
        if(s==z[y]){
            cout<<y+1;
            return 0;
        }
    }
    double suma=0;
    int tam=s.size();
    for(int i=1;i<=INT_MAX;i++){
        suma+=log10(i);
        if((int)suma + 1 == tam){
            cout<<i;
            break;
        }
    }
    return 0;
}
