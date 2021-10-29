#include <bits/stdc++.h>
#define EPS 1e-7

using namespace std;

double z[21];
struct cmp {
    bool operator () ( const long double &a, const long double &b ) const {
        return a + EPS < b;
    }
};
set < double , cmp > num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    double p,barra;
    cin>>p>>barra;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    int con =0;
    for(int mask=1;mask<(1<<n);mask++){
        double suma = barra;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                suma += (double)(z[i] * 2);
            }
        }
        if(fabs(suma-p) <= EPS || suma > p){
            if(num.find(suma) == num.end()){
                num.insert(suma);
                con++;
            }
        }
    }
    (con ? cout<<con : cout<<"Strong");
    return 0;
}

