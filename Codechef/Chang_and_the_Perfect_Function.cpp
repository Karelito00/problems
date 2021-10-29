#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,b;
    cin>>a>>b;
    int suma = 0;
    for(long long i=1;i<=a;i++){
        suma += sqrt((i*i)+b) - i;
    }
    cout<<suma;
    return 0;
}
