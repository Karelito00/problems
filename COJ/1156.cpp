#include <iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
while(1){
    int n;
    cin>>n;
    if(n==42)
        break;
    cout<<n<<"\n";
}
    return 0;
}