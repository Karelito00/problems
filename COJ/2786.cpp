#include <cstdio>

using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if(a%2==0)
        printf("%d",(a*a)/2);
    else
        printf("%d",(((a*a)+1)/2));
    return 0;
}
