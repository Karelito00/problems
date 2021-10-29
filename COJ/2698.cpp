#include <iostream>

using namespace std;

int main()
{
    string a;
    cin>>a;
    int b=0;
    for(int c=0;c<a.size();c++){
        b+=a[c]-'A'+1;
    }
    cout<<b;
    return 0;
}