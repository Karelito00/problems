#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double n,m;
    cin>>n>>m;
    double suma=0;
    for(int i=0;i<n;i++){
        double t;
        cin>>t;
        suma+=t;
    }
    double promedio=suma/(double)n;
    int con=0;
    while(promedio < (m-1)+0.5){
        suma+=m;
        con++;
        promedio = suma/(n+con);
    }
    cout<<con;
    return 0;
}
