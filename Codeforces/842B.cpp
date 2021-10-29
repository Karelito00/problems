#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double r, d;
    cin>>r>>d;
    d = r - d;
    int salch;
    cin>>salch;
    int con = 0;
    while(salch--){
        double y, x, r1;
        cin>>y>>x>>r1;
        double aux = sqrt((y * y) + (x * x));
        if(aux - r1 >= d && aux + r1 <= r)
            con++;
    }
    cout<<con;
    return 0;
}
