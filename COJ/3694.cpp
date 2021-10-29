#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1){
    int number;
    cin>>number;
    if (number == 0)
        break;
    int cCount = 0;
    for (int i = 1; i <= number/i/i; i++){
        long long d = i*i*i;
        if (number%d == 0)
          cCount++;
    }
    cout<<cCount<<"\n";
    }
    return 0;
}
